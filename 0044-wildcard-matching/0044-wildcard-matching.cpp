class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,s.size(),p.size(),dp);
    }

    bool solve(string &s,string &p,int n,int m,vector<vector<int>> &dp){
        if(n == 0 && m == 0) return dp[n][m] =  true;
        if(m == 0) return dp[n][m] =  false;
        if(n < 0) return false;

        if(dp[n][m] != -1) return dp[n][m];

        if(n > 0 && (s[n-1] == p[m-1] || p[m-1] == '?')){
            return dp[n][m] = solve(s,p,n-1,m-1,dp);
        }else if(p[m-1] == '*'){
            return dp[n][m] =  solve(s,p,n,m-1,dp) | solve(s,p,n-1,m,dp);
        }

        return dp[n][m] =  false;
    
    }
};