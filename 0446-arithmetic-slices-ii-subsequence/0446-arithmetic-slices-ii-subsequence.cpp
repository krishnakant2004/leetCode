class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long,int>> dp(n);

        long long ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                long long diff = (long long)nums[i] - nums[j];
                long long cnt = dp[j].count(diff) ? dp[j][diff] : 0;
              
                //update
                ans += cnt;
                dp[i][diff] += 1 + cnt;
            }
        }
        return (int)ans;
    }
};