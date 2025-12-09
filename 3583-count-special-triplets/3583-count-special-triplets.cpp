class Solution {
public:
    int const MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
         unordered_map<int,int> mp1;
         unordered_map<int,int> mp2;
         unordered_map<int,int> mp3;

         for(int i = 0;i<n;i++){
            //3size
            if(nums[i] % 2 == 0){
                mp3[nums[i]] += mp2[nums[i]/2];
                if(mp3[nums[i]] >= MOD) mp3[nums[i]] -= MOD;
            }
                
            //2 size
            mp2[nums[i]] += mp1[nums[i]*2];
            if(mp2[nums[i]] >= MOD) mp2[nums[i]] -= MOD;
            //1 size
            mp1[nums[i]] += 1;
            if(mp1[nums[i]] >= MOD) mp1[nums[i]] -= MOD;
         }
         long long sum = 0;
         for(auto &val : mp3){
            sum += val.second;
            if(sum >= MOD) sum -= MOD;
         }
         return sum;
    }
};