class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &val : nums) mp[val]++;
        int mf = mp[nums[0]];
        for(auto  &p : mp){
           mf = max(p.second , mf);
        }
        int count = 0;
        for(auto &p : mp){
            if(p.second == mf) count += mf;
        }
        return count;
    }
};