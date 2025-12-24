class Solution {
public:
    const long long LIMIT = INT_MAX;
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return getDist(s,t,n,m,dp);

        //bottom up
          vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    if (dp[i][j] > LIMIT) dp[i][j] = LIMIT;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }

    int getDist(string& s,string& t,int n,int m,vector<vector<int>> &dp){
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(s[n-1] == t[m-1]){
            return dp[n][m] =  getDist(s,t,n-1,m-1,dp) + getDist(s,t,n-1,m,dp);
        }else{
            return dp[n][m] = getDist(s,t,n-1,m,dp) ;
        }
    }
};