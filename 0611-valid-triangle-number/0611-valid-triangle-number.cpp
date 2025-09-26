class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();

        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){

                for(int k = j+1;k<n;k++){
                    if(nums[k] < (nums[i]+nums[j])) count++;
                }
            }
        }
        return count;
    }

    
};