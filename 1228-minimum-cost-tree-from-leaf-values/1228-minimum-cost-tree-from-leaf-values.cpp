class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int maxLeafNode = 1;
        vector<vector<pair<int,int>>> dp(arr.size(),vector<pair<int,int>>(arr.size(),{-1,-1}));
        
        return solve(arr,0,arr.size()-1,maxLeafNode,dp);
    }

    int solve(vector<int>& arr,int i,int j,int &maxLeafNode,vector<vector<pair<int,int>>> &dp){
        if(i == j){
            maxLeafNode = arr[i];
            return 0;
        }

        if(dp[i][j].first != -1){
            maxLeafNode = dp[i][j].second;
            return  dp[i][j].first;
        }

        int minSum = INT_MAX;
        int maxLeaf = INT_MIN;
        for(int k = i;k<j;k++){
            int maxLeafLeft = 1;
            int maxLeafRight = 1;
            int leftSum = solve(arr,i,k,maxLeafLeft,dp);
            int rightSum = solve(arr,k+1,j,maxLeafRight,dp);
            int currVal = maxLeafLeft *  maxLeafRight;
            minSum = min(minSum , (currVal+leftSum+rightSum));
            maxLeaf = max({maxLeaf , maxLeafLeft , maxLeafRight});
        }

        dp[i][j] = {minSum , maxLeaf};
        maxLeafNode = maxLeaf;
        return minSum;
    }
};