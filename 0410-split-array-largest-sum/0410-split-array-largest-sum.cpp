class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
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
};