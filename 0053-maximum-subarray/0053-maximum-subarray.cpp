class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxVal = -100000;
        for(int i = 0;i<nums.size();i++){
            if(sum + nums[i] <=0){
                maxVal = max(maxVal , sum + nums[i]);
                sum = 0;
                continue;
            }
            maxVal = max(maxVal , sum + nums[i]);
            sum = sum + nums[i];
        }
        return maxVal;
    }
};