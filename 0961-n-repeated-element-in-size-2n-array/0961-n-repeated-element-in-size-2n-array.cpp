class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++) mp[nums[i]]++;
        for(auto const  &v : mp) {
            if(v.second == n) return v.first;
        }
        return -1;
    }
};