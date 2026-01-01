class Solution {
public:
   int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
    int n = nums.size();
    vector<int> sumL(n, 0), sumM(n, 0);

    // window sums
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
        if (i >= L) s -= nums[i - L];
        if (i >= L - 1) sumL[i] = s;
    }

    s = 0;
    for (int i = 0; i < n; i++) {
        s += nums[i];
        if (i >= M) s -= nums[i - M];
        if (i >= M - 1) sumM[i] = s;
    }

    // prefix max
    vector<int> maxL(n, 0), maxM(n, 0);
    maxL[0] = sumL[0];
    maxM[0] = sumM[0];

    for (int i = 1; i < n; i++) {
        maxL[i] = max(maxL[i - 1], sumL[i]);
        maxM[i] = max(maxM[i - 1], sumM[i]);
    }

    int ans = 0;

    // L before M
    for (int i = L + M - 1; i < n; i++) {
        ans = max(ans, maxL[i - M] + sumM[i]);
    }

    // M before L
    for (int i = L + M - 1; i < n; i++) {
        ans = max(ans, maxM[i - L] + sumL[i]);
    }

    return ans;
}

};