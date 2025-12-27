class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res = {{}};
        
    //     for(int i = 0;i<nums.size();i++){
    //         vector<vector<int>> vec = res;
    //         for(auto v : res){
    //             v.push_back(nums[i]);
    //             vec.push_back(v);
    //         }
    //         res = vec;
    //     }
    //     return res;
    // }

    //using bit manupulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;   // 2^n subsets

        vector<vector<int>> ans;

        for(int mask = 0; mask < total; mask++) {
            vector<int> subset;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }


};