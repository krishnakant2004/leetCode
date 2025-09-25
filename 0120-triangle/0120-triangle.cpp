class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = 0;
        int n = triangle.size();

        vector<vector<int>> dp(n);
        for(int i = 0;i<triangle.size();i++){
            int m = triangle[i].size();
            dp[i].resize(m,INT_MAX);
        }
        return solve(triangle,0,0,dp);

    }
    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        int n = triangle.size();
        if(i == n) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(solve(triangle,i+1,j,dp) , solve(triangle,i+1,j+1,dp));
        
    }
};