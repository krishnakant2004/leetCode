class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1 , vector<int>(amount+1 , -1));
        return solve(coins , amount , coins.size() , dp);
    }

    int solve(vector<int>& coins , int amount , int n , vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(n == 0 || amount < 0) return 0;

        if(dp[n][amount] != -1) return dp[n][amount];

        int a1 = solve(coins , amount - coins[n-1] , n ,dp);
        int a2 = solve(coins , amount  , n - 1,dp);
        return dp[n][amount] = a1 + a2;
    }
};