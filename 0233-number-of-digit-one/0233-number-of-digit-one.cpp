class Solution {
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        int size = str.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(2,vector<int>(11,-1)));
        return solve(str,dp,0,1,0);
    }

    int solve(string& str,vector<vector<vector<int>>>& dp,int idx,int bound,int cnt){
        if(idx == str.size()) return cnt;

        if(dp[idx][bound][cnt] != -1) return dp[idx][bound][cnt];

        int ans = 0;
        int tight = ((bound == 0) ? 9 : (str[idx] - '0'));

        for(int i = 0;i <= tight; i++){
            int undateCnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(str,dp,idx+1,(bound & i == str[idx]-'0'),undateCnt);
        }
        return dp[idx][bound][cnt] = ans;
    }
};