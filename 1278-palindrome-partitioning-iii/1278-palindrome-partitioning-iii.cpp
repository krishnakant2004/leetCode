class Solution {
public:
    bool isPalindrom(string &s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }

    int palindromePartition(string s, int limit) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                cost[i][j] = cost[i+1][j-1];
                if (s[i] != s[j]) cost[i][j]++;
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(limit+1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= limit; k++) {
                for (int j = k-1; j < i; j++) {
                    if (dp[j][k-1] != INT_MAX) {
                        dp[i][k] = min(dp[i][k],
                                       dp[j][k-1] + cost[j][i-1]);
                    }
                }
            }
        }
        return  dp[n][limit];
    }
};