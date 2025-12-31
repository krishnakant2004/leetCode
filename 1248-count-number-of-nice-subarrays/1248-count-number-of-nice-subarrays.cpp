class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k);
        
       int a = lessThanEqualToNumber(nums,k);
       int b = lessThanEqualToNumber(nums,k-1);
       return a-b;
    }

    int lessThanEqualToNumber(vector<int>& nums, int k){
        int st = 0;
        int end = 0;
        int count = 0;
        int odd = 0;

        while(end < nums.size()){
            if(nums[end] % 2 == 1) odd++;

            while(odd > k && st < end){
                if(nums[st] % 2 == 1) odd--;
                st++;
            }

            if(k == 0 && odd > 0){
                odd--;
                end += 1;
                st = end;
                continue;
            }

            count += (end - st + 1);
            end++; 
        }
        return count;
    }

    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int n = nums.size();

        int ans = 0;
        int odd = 0;
        mp[0] = 1;
        for(int i = 0;i<n;i++){
            if(nums[i] % 2 == 1) odd++;
            if(mp.count(odd - k)){
                ans += mp[odd-k];
            }
            mp[odd] += 1;
        }
        return ans;
    }
};