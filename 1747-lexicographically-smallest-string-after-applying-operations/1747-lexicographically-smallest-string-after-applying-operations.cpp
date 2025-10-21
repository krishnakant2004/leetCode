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
        str = str.substr(str.size()-b) + str.substr(0,str.size()-b);
    }
    void add(string& str,int a){
        for(int i = 1;i<str.size();i += 2){           
            str[i] = (((str[i] - '0') + a) % 10) + '0';
        }
    }
};