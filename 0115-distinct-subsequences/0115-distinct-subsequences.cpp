class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return getDist(s,t,n,m,dp);
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