class Solution {
public:
    int countPrimes(int n) {
        vector<int> dp(n+1,true);
        if(n < 2) return 0;

        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i*i<=n;i++){
            if(dp[i]){
               for(int j = i*i; j <= n; j += i){
                dp[j] = false;
               }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(dp[i]) cnt++;
        }
        return cnt;
    }
};