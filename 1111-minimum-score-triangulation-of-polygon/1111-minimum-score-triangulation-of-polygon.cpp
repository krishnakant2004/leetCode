class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
      int n = (int)A.size();
        // dp[i][j] = min score to triangulate polygon from i to j (inclusive)
        // only defined for j > i; use long long to avoid overflow
        const long long INF = (1LL<<62);
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // length = difference j - i
        for (int len = 2; len < n; ++len) { // need at least 2 to form a triangle (i, i+1, i+2 -> len=2)
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                long long best = INF;
                for (int k = i + 1; k <= j - 1; ++k) {
                    long long cost = dp[i][k] + (long long)A[i] * A[k] * A[j] + dp[k][j];
                    if (cost < best) best = cost;
                }
                dp[i][j] = (best == INF ? 0 : best);
            }
        }
        return dp[0][n-1];
    }

   
};