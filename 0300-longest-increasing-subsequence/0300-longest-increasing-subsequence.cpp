class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return LIS(nums);
        // unordered_map<string,int> map;
        // return solve(nums,map,INT_MAX,nums.size());
    }

    int LIS(vector<int>& nums){
        int n = nums.size();

        vector<int> dp(n+1,1);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                if(nums[j-1] < nums[i-1]){
                    dp[i] = max(dp[i] , 1 + dp[j]);
                }
            }
        }
        int maxCount  = 1;
        for(auto const &val : dp){
            maxCount = max(maxCount , val);
        }
        return maxCount;
    }

    int solve(vector<int>& nums,unordered_map<string,int> &map,int prev,int n){
        if(n == 0) return 0;
        string str = to_string(prev) + "-"+to_string(n);

        if(map.find(str) != map.end()) return map[str];


        int m = INT_MIN;
        if(nums[n-1] < prev){
            m  = max(m,1+ solve(nums,map,nums[n-1],n-1));
        }
        m = max(m , solve(nums,map,prev,n-1));
        return map[str] = m;
    }
};