class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        long long prd = 1;
        int left = 0;
        for(int right = 0;right < n; right++){
            prd *= nums[right];
            
            while(prd >= k && left <= right){
                prd = prd/nums[left];
                left++;
            }
            ans += (right - left +1);
        }
        return ans;
    }
};