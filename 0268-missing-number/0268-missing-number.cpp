class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = (n*(n+1))/2;
        long long actualSum = 0;
        for(int i = 0;i<n;i++){
            actualSum += nums[i];
        } 
        return sum - actualSum;
    }
};