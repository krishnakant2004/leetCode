class Solution {
public:
    int longestValidParentheses(string s) {
        return lvp(s);

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


     int lvp(string s) {
        int n = s.size();

        int longestPar = 0;
        int close = 0;
        int open = 0;

        int left = 0;
        int right = 0;
        while(right < n){
            if(s[right] == '('){
                open++;
            }else{
                close++;
            }
            if(open == close) longestPar = max(longestPar , right-left+1);
            if(close > open){
                right++;
                left = right;
                open = 0;
                close = 0;
                continue;
            }
            right++;
        }
       
        left = n-1;
        right = n-1;
        open = 0;
        close = 0;
        while(left >= 0){
            if(s[left] == ')'){
                close++;
            }else{
                open++;
            }
            if(open == close) longestPar = max(longestPar , right-left+1);
            if(open > close){
                open = 0;
                close = 0;
                left--;
                right = left;
                continue;
            }
            left--;
        }
       return longestPar;
    }
};