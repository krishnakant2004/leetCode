class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int left = 0, odd = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2) odd++;

            while (odd > k) {
                if (nums[left] % 2) odd--;
                left++;
            }

            count += (right - left + 1);
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