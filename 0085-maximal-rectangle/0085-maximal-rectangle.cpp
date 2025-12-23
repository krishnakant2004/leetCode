class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        vector<int> dp(m,0);
        for(int i = 0;i<n;i++){

            //add val tp dp
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == '0'){
                    dp[j] = 0;
                }else{
                    dp[j] +=1;
                }
            }

            vector<int> a1(m,0);
            findAreaForward(dp,a1,m);
            findAreaBackward(dp,a1,m);
            for(int i = 0;i<m;i++){
                maxArea = max(maxArea , a1[i]);
            }
        }
        return maxArea;
    }

    void findAreaForward(vector<int> &dp,vector<int> &a1,int m){
        stack<int> st; // idx

        for(int i = 0;i<m;i++){
            int curr = dp[i];
            while(!st.empty() && dp[st.top()] >= curr){
                st.pop();
            }
            if(st.empty()){
                a1[i] = (i+1) * dp[i];
            }else{
                a1[i] = (i - st.top()) * dp[i];
            }
            st.push(i);
        }
    }

    void findAreaBackward(vector<int> &dp,vector<int> &a1,int m){
        stack<int> st; // idx

        for(int i = m-1;i>=0;i--){
            int curr = dp[i];
            while(!st.empty() && dp[st.top()] >= curr){
                st.pop();
            }
            if(st.empty()){
                a1[i] += (m - i - 1) * dp[i];
            }else{
                a1[i] += (st.top() - i - 1) * dp[i];
            }
            st.push(i);
        }
    }

};