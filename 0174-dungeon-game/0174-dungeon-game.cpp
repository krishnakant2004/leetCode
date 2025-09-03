class Solution {
public:
    unordered_map<string,int> Map;
    int solve(vector<vector<int> > &A,vector<vector<int>> &dp,int i,int j){
        int n = A.size();
        int m = A[0].size();
        if(i == n-1 && j == m-1){
            if(A[i][j] > 0) return 0;
            else return -(A[i][j]);
        }

        if(dp[i][j] != -1) return dp[i][j];

        int minAns = INT_MAX;
        if(i+1 < n){
            int a = solve(A,dp,i+1,j);
            minAns = min(minAns , a);
        }
        if(j+1 < m){
            int b = solve(A,dp,i,j+1);
            minAns = min(minAns , b);
        }
        if((A[i][j] - minAns) >= 0) return 0;
        return dp[i][j] = -(A[i][j] - minAns);
    }

    int calculateMinimumHP(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return 1 + solve(A,dp,0,0);
    }
};