class Solution {
public:
    int search(vector<int>& nums, int target) {
        return getIdx(nums,target);
        return solve(nums,0,nums.size()-1,target);
    }

    int solve(vector<int>& nums,int st,int end, int target){
        if(st > end) return -1;

        int mid = st + (end-st)/2;
        if(nums[mid] == target) return mid;

        if((mid-1 >= 0 && nums[mid] < nums[mid-1]) || (mid+1 < nums.size() && nums[mid+1] < nums[mid])){
            if(target > nums[nums.size()-1]){
                return solve(nums,st,mid-1,target);
            }else{
                return solve(nums,mid+1,end,target);
            }

        }else{
            if(nums[mid] > nums[nums.size()-1]){
                if(target < nums[mid] && target >= nums[0]){
                    return solve(nums,st,mid-1,target);
                }else{
                    return solve(nums,mid+1,end,target);
                }
            }else{
                if(target > nums[mid] && target <= nums[nums.size()-1]){
                    return solve(nums,mid+1,end,target);
                }else{
                    return solve(nums,st,mid-1,target);
                }
            }
        }
        return -1;
    }

    int getIdx(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > nums[n-1]){
                if(target > nums[mid]){
                    l = mid+1;
                }else if(target >= nums[0]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(target < nums[mid]){
                    r = mid-1;
                }else if(target > nums[n-1]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }

        return -1;
    }
};