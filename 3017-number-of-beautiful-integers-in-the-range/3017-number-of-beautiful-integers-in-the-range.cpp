class Solution {
    int dp[11][2][2][11][11][101]; 
    // idx, bound, started, even, odd, remainder
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string rightStr = to_string(high);
        string leftStr = to_string(low - 1);

        memset(dp, -1, sizeof(dp));
        int rightAns = solve(rightStr, k, 0, 1, 0, 0, 0, 0);

        memset(dp, -1, sizeof(dp));
        int leftAns = (low > 0) ? solve(leftStr, k, 0, 1, 0, 0, 0, 0) : 0;

        return rightAns - leftAns;
    }

    int solve(string &str, int k, int idx, int bound, int started, int even, int odd, int remainder) {
        if (idx == str.size()) {
            return (started && even == odd && remainder == 0);
        }

        int &res = dp[idx][bound][started][even][odd][remainder];
        if (res != -1) return res;

        int limit = bound ? str[idx] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            int nBound = bound && (d == limit);
            int nStarted = started || (d != 0);

            int nEven = even, nOdd = odd;
            if (nStarted) {
                if (d % 2 == 0) nEven++;
                else nOdd++;
            }

            int nRem = (remainder * 10 + d) % k;
            ans += solve(str, k, idx + 1, nBound, nStarted, nEven, nOdd, nRem);
        }

        return res = ans;
    }
};
