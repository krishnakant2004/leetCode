class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();

        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                int idx = getIdx(nums,j+1,n-1,nums[i]+nums[j]);
                count += (idx - j);
            }
        }
        return count;
    }

    int getIdx(vector<int>& vec,int l,int r,int sum){
        if(l > r) return r;

        int mid = l + (r-l)/2;
        if(vec[mid] < sum){
            return getIdx(vec,mid+1,r,sum);
        }else{
            return getIdx(vec,l,mid-1,sum);
        }
    }

    
};