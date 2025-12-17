class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins,amount);


        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        for(int i = 0;i<=n;i++){
            dp[0][i] = 0;
        }

        for(int amt = 1;amt<=amount;amt++){
           for(int i = 1;i<=n;i++){
                if(amt >= coins[i-1]){
                    dp[amt][i] = min(dp[amt][i-1] == -1 ? INT_MAX : dp[amt][i-1] , dp[amt-coins[i-1]][i]  == -1 ? INT_MAX : 1 + dp[amt-coins[i-1]][i]);
                    if(dp[amt][i] == INT_MAX) dp[amt][i] = -1;
                }else{
                    dp[amt][i] = dp[amt][i-1];
                }
                
           }
        }
        return dp[amount][n];

    }

    // using 1d dp
    int solve(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX);
        int n = coins.size();

        dp[0] = 0;

        for(int amt = 1;amt<=amount;amt++){
            for(int i = 0;i<n;i++){
                if(amt >= coins[i]){
                    dp[amt] = min(dp[amt] , dp[amt - coins[i]] == INT_MAX ? INT_MAX : 1 + dp[amt - coins[i]]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};