class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        int sum = 0;
        int ans = 0;
        mp[0] = 0;
        for(int i = 1;i<=nums.size();i++){
            sum += (nums[i-1] == 0 ? -1 : 1);
            if(mp.count(sum)){
                ans = max(ans , i - mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return ans;
     }
};