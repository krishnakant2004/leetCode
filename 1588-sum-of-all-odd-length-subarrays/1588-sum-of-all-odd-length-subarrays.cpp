class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        vector<int> vec(n,0);
        for(int i  = 0;i<n;i++){
            sum += nums[i];
            vec[i] = sum;
        }
        
        for(int len = 3 ;len<=n;len += 2){
            for(int i = 0;i<=n-len;i++){
                int j = i + len - 1;
                sum += vec[j] -( i-1  < 0 ? 0 : vec[i-1]);
            }
        }
        return sum;
    }
};