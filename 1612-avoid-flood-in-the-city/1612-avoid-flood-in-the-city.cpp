

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> mp;
        vector<int> ans(n,-1);

        for(int i = 0;i<n;i++){
            if(rains[i] == 0){
                ans[i] = 0;
            }
        }

        for(int i = 0;i<n;i++){
            int val = rains[i];
            if(val == 0) continue;

            if(mp.find(val) == mp.end()){
                mp[val] = i;
            }else{
                bool find = false;
                for(int j = mp[val]+1;j<i;j++){
                  if(ans[j] == 0){
                     ans[j] = val;
                     mp[val] = i;
                     find = true;
                     break;
                  }
                }
                if(find == false) return {};
                
            }
        }
        for(int i = 0;i<n;i++){
            if(ans[i] == 0) ans[i] = 1;
        }
        return ans;
    }
};