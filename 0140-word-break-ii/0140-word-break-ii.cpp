class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> store;
        string str = "";
        solve(s,s.size(),wordDict,store,str);
        return store;
    }

    void solve(string &s,int n, vector<string>& wordDict,vector<string>& store,string &str){
        if(n  <= 0){
            store.push_back(str);
            return;
        }
        string s1 = str;
        for(int i = 0;i<wordDict.size();i++){
            if(wordDict[i].size() <= n && wordDict[i] == s.substr(n-wordDict[i].size(),wordDict[i].size()) ){
                str = wordDict[i] + str;
                if(n-wordDict[i].size() > 0)
                    str = " " + str;
                solve(s,n-wordDict[i].size(),wordDict,store,str);
                str = s1;
            }
        }
    }
};