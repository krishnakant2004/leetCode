class Solution {
public:
    unordered_map<string,int> map;

    string makeKey(int idx,int tight,int sum,int product){
        return to_string(idx)+"."+to_string(tight) + "."+to_string(sum)+"."+to_string(product); 
    }

    int beautifulNumbers(int l, int r) {
        string ls = to_string(l-1);
        string rs = to_string(r);
        
        int a1 = r ? solve(rs,0,1,0,1) : 0;
        map.clear();

        int a2 = l-1 ? solve(ls,0,1,0,1) : 0;
        return a1 - a2;
    }

    int solve(string &str,int idx,int tight,int sum,int product){
        if(idx == str.size()) return sum ? product % sum == 0 : 0;

        string sKey = makeKey(idx,tight,sum,product); 

        if(map.find(sKey) != map.end()) return map[sKey];

        int ans = 0;
        int limit = (tight == 1) ? str[idx]-'0' : 9; 
        for(int i = 0;i<=limit;i++){
            int Nprod = i * (sum ? product : 1);
            ans += solve(str,idx+1,(tight & (i == limit)),sum+i,Nprod);
        }
        map[sKey] = ans;
        return ans;
    }
};