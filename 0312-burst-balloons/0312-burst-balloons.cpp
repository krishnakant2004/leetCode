class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<n-1;i++){
            dp[i][i+1] = 0;
        }
        

        //len >= 3
        for(int len = 3 ; len <= n;len++){
            for(int i = 0;i <= n-len;i++){
                int j = i+len-1;
                for(int k = i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k][j] + nums[i]*nums[j]*nums[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};