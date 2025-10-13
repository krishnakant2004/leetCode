class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int> st;
        int n = words.size();
        st.push_back(0);

      
        int i = 1;
        while(i < words.size()){
            int idx = st[st.size()-1];
            string s1 = words[idx];
            string s2 = words[i];
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());

            if(s1 != s2){
                st.push_back(i);
            }
            i++;
        }
        vector<string> store;
        for(int i = 0;i<st.size();i++){
            store.push_back(words[st[i]]);
        }
        return store;
    }
};