class Solution {
public:
    int const MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        return minSumSubarray(arr);

        int n = arr.size();

        vector<int> minVec(arr.size(),0);
        int minVal = 0;
        for(int i = 0;i<arr.size();i++){
            minVec[i] = arr[i];
            minVal = (minVal + arr[i]) % MOD;
        }
        
        for(int len = 2; len <= n ; len++){

            for(int i = 0;i + len -1 < n ;i++){
                int j = i + len -1;
                minVec[i] = min(minVec[i] , arr[j]);
                minVal = (minVal + minVec[i]) % MOD;
            }
        }
        return minVal;
    }

    int minSumSubarray(vector<int>& nums){
        //forward
        int n = nums.size();

        vector<int> forward(n+1,0);
        vector<int> backward(n+1,0);

        int minVal = 0;
        stack<int> st;
        for(int i = 1;i<=n;i++){
            int curr = nums[i-1];
            while(!st.empty() && nums[st.top()-1] >= curr){
                st.pop();
            }
            if(st.empty()){
                forward[i] = 0;
            }else{
                forward[i] = st.top();
            }
            st.push(i);

        }

        //backward pass
        stack<int> bst;
        for(int i = n;i>0;i--){
            int curr = nums[i-1];
            while(!bst.empty() && nums[bst.top()-1] > curr){
                bst.pop();
            }
            if(bst.empty()){
                backward[i] = n+1;
            }else{
                backward[i] = bst.top();
            }
            bst.push(i);
        }
        long long sum = 0;
        for(int i = 1;i<=n;i++){
            long long left = i - forward[i];
            long long right = backward[i] - i;

            long long contrib = (left * right) % MOD;
            contrib = (contrib * nums[i-1]) % MOD;

            sum = (sum + contrib) % MOD;
        }
        return sum;

    }
};