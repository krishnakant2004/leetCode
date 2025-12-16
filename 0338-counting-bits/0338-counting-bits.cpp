class Solution {
public:
    vector<int> countBits(int n) {
        unordered_map<int,int> mp;
        vector<int> res(n+1,0);
        res[0] = 0;
        mp[0] = 0;
        for(int i = 1;i<=n;i++){
            int val = mp[i>>1] + (i & 1);
            mp[i] = val;
            res[i] = val; 
        }
        return res;
    }
};