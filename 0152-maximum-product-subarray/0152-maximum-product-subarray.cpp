class Solution {
public:

    //0(n^2)
    int maxProduct(vector<int>& nums) {
        return maxProd(nums);


        int maxPrd = INT_MIN;
        int n = nums.size();

        vector<int> dp(n , 0);
        for(int i = 0;i<n;i++){
            dp[i] = nums[i];
            maxPrd = max(maxPrd , dp[i]); 
        }

        // for len 2 to n
        for(int len = 2;len <= n;len++ ){
            for(int i = 0;i<=n-len;i++){
                int j = i + len -1;
                int newPrd = dp[i] * nums[j];
                maxPrd = max(maxPrd , newPrd);
                dp[i] = newPrd;
            }
        }
        return maxPrd;
    }

    // o(n)

    int maxProd(vector<int>& nums){
        int n = nums.size();

        int maxP = INT_MIN;
        int prd = 1;
        // form start
        for(int i = 0;i<n;i++){
            prd *= nums[i];
            maxP = max(maxP , prd);
            if(nums[i] == 0){
                prd = 1;
            }
        }
        //from end
        prd = 1;
        for(int i = n-1;i>=0;i--){
            prd *= nums[i];
            maxP = max(maxP , prd);
            if(nums[i] == 0){
                prd = 1;
            }
        }
        return maxP;
    }
};