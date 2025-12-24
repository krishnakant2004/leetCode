class Solution {
public:
    bool isPalindrom(string &s,int i,int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 1;i<n;i++){
            int j = 0;
            while(j <= i){
                if(isPalindrom(s,j,i)){
                    dp[i+1] = min(dp[i+1] , j==0 ? 0 : 1 + dp[j]);
                }
                j++;
            }
        }
        return dp[n];
    }
};