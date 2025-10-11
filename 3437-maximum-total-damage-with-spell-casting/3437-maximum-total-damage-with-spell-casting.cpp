class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        //sol1
        int n = power.size();
        vector<long long> dp(n+1,-1);
        sort(power.begin(),power.end());
        return solve(power,dp,power.size());
    }

    long long solve(vector<int>& power,vector<long long> &dp,int n){
        if(n <= 0) return 0;
        if(dp[n] != -1) return dp[n];

        int curr = power[n-1];

        auto[idx,count] = getIdx(power,curr,n-1);

        long long ans = INT_MIN;
        long long sum = (long long)curr * (count+1); 
        ans = max(ans , sum + solve(power,dp,idx));

       
        ans = max(ans ,(long long)solve(power,dp,n-count-1));
        return dp[n] = ans;
       
    }

    pair<int,int> getIdx(vector<int>& power,int curr,int n){

        int count = 0;
        while(n > 0){
            if(power[n-1] == curr) count++;
            if(power[n-1] < curr - 2) return {n,count};
            n--;
        }
        return {0,count};
    }



};