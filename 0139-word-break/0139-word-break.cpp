class Solution {
public:
    bool isCkeck(string &str , string &word , int i){
        int j= 0;
        while(j < word.size()){
            if(word[j] != str[i]) return false;
            j++;
            i++;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            for(auto &word : wordDict){
                if(word.size() > i) continue;
                int pIdx = i-word.size();
                if(isCkeck(s,word,pIdx)){
                    if(dp[pIdx]){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};