class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return spa(nums,k);
        return using_binary_division(nums,k);
        //
        int n = nums.size();
        if(k > n) return -1; 
        vector<vector<int>> st(n,vector<int>(k+1,0));
        //prefix sum
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i];
            st[i][1] = sum; 
        }
        if(k == 1) return sum;

        for(int i = 2;i<k;i++){
            for(int j = i-2;j<(n - k + i);j++){
                int maxVal = INT_MAX;
                for(int p = i-2;p<j;p++){
                    int prevK = st[p][i-1];
                    int currVl = st[j][1] - st[p][1];
                    maxVal = min(maxVal , max(prevK,currVl));

                }
                st[j][i] = maxVal;
                // cout<<"max :"<<maxVal<<endl;
            }
        }
        int minLargest = INT_MAX;
        for(int i = k-2;i<n-1;i++){
            // cout<<"pre: "<<st[i][k-1]<<" curr"<<st[n-1][1] - st[i][1]<<endl;
            int v = max(st[i][k-1] , st[n-1][1] - st[i][1]);
            minLargest = min(minLargest , v);
        }
        return minLargest;
    }

    int using_binary_division(vector<int>& nums, int k){
        int l = 0;
        int r = 0;

        for(int i = 0;i<nums.size();i++){
            l = max(l , nums[i]);
            r += nums[i];
        }
        int ans = r;
        while( l <= r){
            int mid = l + (r-l)/2;
            
            if(isfesable(nums,mid,k)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }

    bool isfesable(vector<int>& nums,int mid,int k){
        int part = 1;
        int n = nums.size();

        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum > mid){
                part++;
                sum = nums[i];
                if(part > k) return false;
            }
        }
        return true;
    }

    int spa(vector<int>& nums, int k){
         int n = nums.size();
        if(k > n) return -1; 
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //prefix sum
        int sum = 0;

        for(int i = 1;i<=n;i++){
            sum += nums[i-1];
            dp[i][1] = sum; 
        }
        if(k == 1) return sum;

        for(int div = 2; div<=k; div++){
            for(int i = div; i<=n; i++){
                int minV = INT_MAX;
                for(int j = div-1; j<i; j++){
                    int kth = dp[i][1] - dp[j][1];
                    minV = min(minV , max(dp[j][div-1] , kth));
                }
                dp[i][div] = minV;
            }
        }
        return dp[n][k];
    }

};