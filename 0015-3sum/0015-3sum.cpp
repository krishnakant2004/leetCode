class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> store;
        unordered_set<int> dup;
        set<vector<int>> add;

        for(int i=0;i<nums.size();i++){
            store[nums[i]]=i;
        }
        set<vector<int>> arr=help(nums,store,add,dup,0);
        vector<vector<int>> ret_vec;
        for(auto it:arr){
            ret_vec.push_back(it);
        }
        
        return ret_vec;
    }
    
    set<vector<int>> help(vector<int>& nums,unordered_map<int,int> &store,set<vector<int>> &add,unordered_set<int> &dup,int i){
        if(i==nums.size()){
            return add; 
        }

        if(dup.find(nums[i])==dup.end()){
            vector<vector<int>> arr=find_2sum(nums,store,i,-nums[i]);
            if(arr.size()){
                for(auto val:arr){
                    add.insert(val);
                }   
            }
            dup.insert(nums[i]);
        }
        
        return help(nums,store,add,dup,i+1);

    }

    vector<vector<int>> find_2sum(vector<int> &nums,unordered_map<int,int> &store,int k,int target){

        vector<vector<int>> st={};
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(store.count(complement) && i!=k && store[complement]!=i && k!=store[complement]){
                vector<int> vec={nums[i],complement,nums[k]};
                sort(vec.begin(),vec.end());
                st.push_back(vec);
            }

        }
        return st;
    }
    
};