class Solution {
public:
    static bool compare(const pair<int,int>&a , const pair<int,int>&b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> dp(51,0);
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            dp[nums[j]]++;
            if(j - i + 1 == k){
                vector<pair<int,int>> dp1(51);
                for(int i = 0;i<dp.size();i++){
                    dp1[i] = {i , dp[i]};
                }
                sort(dp1.begin()+1,dp1.end(),compare);
                int sum = 0;
                for(int i = 1;i<dp1.size() && i<=x ; i++) sum += dp1[i].second * dp1[i].first;
                ans.push_back(sum);

                dp[nums[i]]--;
                i++;
            }
            
            j++;
        }
        return ans;
    }
};