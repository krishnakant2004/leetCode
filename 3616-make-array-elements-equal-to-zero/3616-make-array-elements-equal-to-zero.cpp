class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n,0);
        vector<int> sufixSum(n,0);
        int sumP = 0;
        int sumS = 0;
        for(int i = 0;i<n;i++){
            sumP += nums[i];
            prefixSum[i] = sumP;

            sumS += nums[n-i-1];
            sufixSum[n-i-1] = sumS;
        }

        int count = 0;
        for(int i = 0 ;i<n;i++){
            if(nums[i] == 0){
                int l = i-1 >= 0 ? prefixSum[i-1] : 0;
                int r = i+1 < n ? sufixSum[i+1] : 0;
                
                if(r-l == 0) count += 2;
                if(abs(r-l) == 1) count += 1;
            }
        }
        return count;
    }
};