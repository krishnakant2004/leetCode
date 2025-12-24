class Solution {
public:
    vector<pair<int,int>> pr = {{-1,0} , {1,0} , {0,1},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(dp[i][j] == -1)
                    ans = max(ans , LIP(matrix ,n,m,i,j,dp,-1));
                else ans = max(ans , dp[i][j]);
            }
        }
        return ans;
    }

    int LIP(vector<vector<int>>& matrix,int n,int m,int i,int j,vector<vector<int>> &dp,int prev){
        if(i < 0 || j < 0) return 0;
        if(i >= n || j >= m) return 0;
        if(matrix[i][j] <= prev) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1;
        for(auto &p : pr){
            int ni = i+p.first;
            int nj = j+p.second;
            ans = max(ans , 1 + LIP(matrix,n,m,ni,nj,dp,matrix[i][j]));
        }
        return dp[i][j] = ans;
    }
};