class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        int ans = n;


        long long sum = 0;
        for(int i = 0;i<n;i++) sum += nums[i];
        int target = sum%p;

        if(target == 0) return 0; 

        unordered_map<int,int> mp;
        mp[0] = 0;
        sum = 0;

        for(int i = 1;i<=n;i++){
            sum += nums[i-1];
            sum  = sum % p;

            int need = (sum - target + p) % p;

            if(mp.count(need)){
                ans = min(ans , i - mp[need]);
            } 
            mp[sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};