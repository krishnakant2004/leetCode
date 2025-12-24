class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))); //idx,sell,tran
        return maxP(prices,1,2,0,dp);
    }

    int maxP(vector<int>& prices ,int sell,int tran,int i,vector<vector<vector<int>>> &dp){
        if(i == prices.size()) return 0;
        if(tran == 0) return 0;
        
        if(dp[i][sell][tran] != -1) return dp[i][sell][tran];

        if(sell == 1){
            return dp[i][sell][tran] = max( maxP(prices,1,tran,i+1,dp) , -prices[i] + maxP(prices,0,tran,i+1,dp));
        }else{
            return dp[i][sell][tran] = max(maxP(prices , 0,tran,i+1,dp) , prices[i] + maxP(prices,1,tran-1,i+1,dp));
        }
    }
};