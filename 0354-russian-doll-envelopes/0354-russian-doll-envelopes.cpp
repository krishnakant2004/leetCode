class Solution {
public:

    //o(nlog(n))
    int maxEnvelopes(vector<vector<int>>& env){
         sort(env.begin(),env.end(),[](auto &a,auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int n = env.size();

        vector<int> list;
        for(int i = 0;i<n;i++){
            int h = env[i][1];
            auto it = lower_bound(list.begin(),list.end(),h);
            
            if(it == list.end()){
                list.push_back(h);
            }else{
                *it = h;
            }
        }
        return list.size();
    }


    // o(n^2)
    int maxEnv1(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](auto &a,auto &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = env.size();
        int t = 1;
        vector<int> dp(n,1);

        for(int i = 0;i<n;i++){
           for(int j = 0;j<i;j++){
            if(env[j][0] < env[i][0] && env[j][1] < env[i][1]){
                dp[i] = max(dp[i] , 1 + dp[j]);
            }
                
           }
        }

        for(int i = 0;i<n;i++){
            t = max(t,dp[i]);
        }
        return t;
    }
};