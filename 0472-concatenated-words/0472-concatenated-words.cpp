class trie {
    public:
    unordered_map<char,trie*> mp;
    bool isLeaf;

    trie(){
        isLeaf = false;
    }

    void insert(const string &word,trie* root,int i){
        if(i == word.size()) {
            root->isLeaf = true;
            return;
        }

        if(root->mp.find(word[i]) != root->mp.end()){
            insert(word,root->mp[word[i]],i+1);
        }
        else{
            trie * newRoot = new trie();
            root->mp[word[i]] = newRoot;
            insert(word,newRoot,i+1);
        }
    }
};

class Solution {
public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie* root = new trie();
        sort(words.begin(),words.end(), [](const string &w1 , const string &w2){ return w1.size()<w2.size();});
        vector<string> store;
        for(auto const &word : words){
            if(!word.size()) continue;
            if(canForm(root,word)) store.push_back(word);
            else root->insert(word,root,0);
        }
        return store;

    }

    private:
    bool canForm(trie* root,const string &str){
        int n = str.size();
        vector<int> dp(n+1,-1);
        return dfs(root,str,0,0,dp);
    }

    bool dfs(trie* root,const string &str,int idx,int count,vector<int> &dp){
        if(idx == str.size()) return count > 1;
        if(dp[idx] != -1) return dp[idx];

        trie* curr = root;
        for(int i = idx;i<str.size();i++){
            if(!curr->mp.count(str[i])) break;
            curr = curr->mp[str[i]];

            if(curr->isLeaf){
                if(dfs(root,str,i+1,count+1,dp)){
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;

    }
};