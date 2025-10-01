class Solution {
public:
    vector<int> arr = {-1,0,1};

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;

        unordered_map<int,int> mp;
        for(int i = 0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        int n = stones.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(stones,1,1,mp,dp);
    }

    bool solve(vector<int>& stones,int n,int jump,unordered_map<int,int> &mp,vector<vector<int>> &dp){
        int size = stones.size();
        if(n == size-1) return true;

        if(dp[n][jump] != -1) return dp[n][jump];

        
        for(int i = 0;i<3;i++){
            int nextVal = stones[n] + (jump + arr[i]);
            if(nextVal > stones[n] && mp.find(nextVal) != mp.end()){
                bool ans = solve(stones,mp[nextVal],(jump + arr[i]),mp,dp);
                if(ans) return dp[n][jump] = true;
            }
        }

        return dp[n][jump] = false;
    }
};