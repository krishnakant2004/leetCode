class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        
        for(int i = 0;i<nums.size();i++){
            vector<vector<int>> vec = res;
            for(auto v : res){
                v.push_back(nums[i]);
                vec.push_back(v);
            }
            res = vec;
        }
        return res;
    }
};