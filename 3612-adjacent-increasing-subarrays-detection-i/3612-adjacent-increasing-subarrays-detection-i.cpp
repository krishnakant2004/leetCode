class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> st(n,1);

        for(int i = n-1;i>=0;i--){
            int nidx = i + k;
            
            if(i+1 < n && nums[i] < nums[i+1]){
                st[i] = 1 + st[i+1];
            }

            if(i+k < n && st[i] >= k && st[i+k] >= k) return true;
        }
        return false;
    }
};