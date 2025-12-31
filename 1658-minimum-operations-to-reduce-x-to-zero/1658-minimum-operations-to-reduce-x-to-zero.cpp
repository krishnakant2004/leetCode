class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        long long sum = 0;
        for(int i = 0;i<n;i++) sum += nums[i];
        long long target = sum - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        sum = 0;
        int len = -1;
        while(r < n){
            sum += nums[r];
                
            while(sum >= target && l <= r){
                if(sum == target) len = max(len , r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }

        return len == -1 ? -1 : n - len;
    }
};