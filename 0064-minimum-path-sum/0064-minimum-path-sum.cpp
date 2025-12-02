class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(grid,0,0,dp);
    }

    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1){
            return grid[n-1][m-1];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int sum = INT_MAX-1;
        if(i+1 < n){
            int s1 = solve(grid,i+1,j,dp);
            sum = min(sum,s1);
        }
        if(j+1 < m){
            int s2 = solve(grid,i,j+1,dp);
            sum = min(s2,sum);
        }

        return dp[i][j] = sum == INT_MAX-1 ? sum : sum+grid[i][j];

    }

    int minPath(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int a = min(minPath(grid , i , j+1,dp) , minPath(grid , i+1 , j,dp));
        if(a == INT_MAX) return dp[i][j] = INT_MAX;

        return dp[i][j] = grid[i][j] + a;
    }
};