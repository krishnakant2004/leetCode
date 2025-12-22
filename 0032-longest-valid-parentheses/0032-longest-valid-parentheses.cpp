class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);

        stack<int> st;
        int maxV = 0;

        int i = 1;
        while(i <= n){
            if(s[i-1] == '('){
                st.push(i);
            }else if(!st.empty()){
               dp[i] = (i - st.top() + 1) + dp[st.top()-1];
               st.pop();
               maxV = max(maxV , dp[i]);
            }
            i++;
        }
        return maxV;
    }
};