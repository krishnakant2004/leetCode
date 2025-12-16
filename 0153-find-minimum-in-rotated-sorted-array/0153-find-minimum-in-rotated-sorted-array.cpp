class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if((mid-1 < 0 || nums[mid-1] > nums[mid]) && (mid+1 >=n || nums[mid] < nums[mid+1])) return nums[mid];

            if(nums[mid] > nums[n-1]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return nums[r];
    }
};