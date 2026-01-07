class Solution {
public:
    int maxPalindromes(string s, int k) {
        ios_base::sync_with_stdio(false);
    cin.tie(0);
        int n = s.size();
        vector<vector<int>> pl(n,vector<int>(n+1,0));

        for(int i = 0;i<n;i++) pl[i][i] = 1;
        //palindrom

        for(int len = 2;len <= n;len++){
            for(int i = 0;i<n-len+1;i++){
                int j = i+ len -1;
                if (s[i] == s[j]) {
                    if (len == 2) 
                        pl[i][j] = 1;
                    else 
                        pl[i][j] = pl[i+1][j-1];
                } else {
                    pl[i][j] = 0;
                }
            }
        }

        vector<int> dp(n+1,0);
        for(int i = k;i<=n;i++){
            dp[i] = dp[i-1];
            for(int j = i-k+1;j>0;j--){
                if(pl[j-1][i-1]){
                    dp[i] = max(dp[i] , 1 + dp[j-1]);
                    break;
                }
            }
        }
        return dp[n];


    }
};
// static const int init = []{
//     struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };    
//     std::atexit(&___::_);
    
//     return 0;
// }();