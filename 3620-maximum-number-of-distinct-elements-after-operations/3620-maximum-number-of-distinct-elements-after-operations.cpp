class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<>());

        //store val freq
        vector<pair<int,int>> pr;
        for(int i = 0;i<n;i++){
            if(i-1 >= 0 && nums[i-1] == nums[i]){
                pr[pr.size()-1].second++;
            }else{
                pr.push_back({nums[i] , 1});
            }
        }
        
        int len = 0;
        int Limit = nums[0] + k;
        for(int i = 0; i<pr.size(); i++){
            int r = min(pr[i].first + k , Limit);
            int l = max(r - pr[i].second , pr[i].first - k-1);

            Limit = l;
            len += (r - l) > 0 ? (r-l) : 0;
        }
        return len;
    }
};