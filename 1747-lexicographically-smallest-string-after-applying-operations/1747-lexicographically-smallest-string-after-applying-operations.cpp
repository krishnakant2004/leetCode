class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> st;
        string finalStr = s;

        solve(s,a,b,st,finalStr);
        return finalStr;
    }

    void solve(string& str,int a,int b,unordered_set<string>& st,string& finalStr){
        if(st.find(str) != st.end()) return;
        finalStr = min(finalStr , str);

        st.insert(str);
        string copyStr = str;

        //add
        add(str,a);
         solve(str,a,b,st,finalStr);
        str = copyStr;

        //rotate;
        rotate(str,b);
         solve(str,a,b,st,finalStr);
        str = copyStr;

    }

    void rotate(string& str,int b){
        vector<char> st(b);
        int j = 0;
        for(int i = str.size()-b;i<str.size();i++){
            st[j] = str[i];
            j++;
        }

        for(int i = str.size()-b-1;i>=0;i--){
            str[i+b] = str[i];
        }

        for(int i = 0;i<st.size();i++){
            str[i] = st[i];
        }
    }
    void add(string& str,int a){
        for(int i = 0;i<str.size();i++){
            if(i % 2 != 0){
                str[i] = (((str[i] - '0') + a) % 10) + '0';
            }
        }
    }
};