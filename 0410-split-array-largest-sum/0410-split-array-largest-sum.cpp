class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid=low + (high-low)/2;
            if(check(nums,mid) <= k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
    }

    int check(vector<int>& nums,int mid){
        int arrSum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(arrSum+nums[i] <= mid){
                arrSum+=nums[i];
            }else{
                count++;
                arrSum=nums[i];
            }
        }

        return count;
    }
};