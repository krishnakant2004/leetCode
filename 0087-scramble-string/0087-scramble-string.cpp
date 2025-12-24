class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;

        string key = s1 + "_" + s2;
        if (mp.count(key)) return mp[key];

        int n = s1.size();

        for(int k = 1; k < n; k++){
            if(isScramble(s1.substr(0,k),s2.substr(0,k)) && isScramble(s1.substr(k),s2.substr(k))) return mp[key] = true;
            if(isScramble(s1.substr(k),s2.substr(0,n-k)) && isScramble(s1.substr(0,k) , s2.substr(n-k))) return mp[key] = true;
        }
        return mp[key] = false;
    }
};