class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        return subSum(nums,k);

        int finalAns = 0;
        int n = nums.size();

        vector<int> sumVec;
        for(int i = 0;i<n;i++){
            sumVec.push_back(nums[i]);
            if(nums[i] % k == 0) finalAns++;
        }

        //for more than 2
        for(int size = 2;size<=n;size++){
            for(int i = 0;i<=n-size;i++){
                int j = i + size - 1;
                int sum = sumVec[i] + nums[j];
                if(sum%k == 0) finalAns++;
                sumVec[i] = sum;
            }
        }
        return finalAns;
    }

    int subSum(vector<int>& nums, int k){
        int n = nums.size();

        unordered_map<int,int> mp;
        long long ps = 0;
        int ans = 0;
        mp[0] = 1;

        for(int i = 0;i<n;i++){
            ps = (ps + nums[i]) % k;
            int fd = (ps + k) % k;
        
            if(mp.count(fd)){
                ans += mp[fd];
            }
            mp[fd] += 1; 
        }
        return ans;
    } 
};