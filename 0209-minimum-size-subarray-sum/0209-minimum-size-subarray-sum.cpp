class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minsize = n+1;

        int sum = 0;
        int l = 0;
        int r = 0;
        while(r < n){
            sum += nums[r];
            if(sum >= target) minsize = min(minsize , r-l+1);
            while(sum >= target && l <= r){
                sum -= nums[l];
                l++;
                if(sum >= target) minsize = min(minsize , r-l+1);
            }
            r++;
        }
        return minsize == n+1 ? 0 : minsize;
    }
};