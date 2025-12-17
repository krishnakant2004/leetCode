class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> store;
        vector<int> vec;
        solve(candidates , target , store,vec,n);
        return store;

    }

    void solve(vector<int>& candidates, int target , vector<vector<int>> &store,vector<int>& vec,int n){
        if(target == 0){
            store.push_back(vec);
            return;
        }
        if(n == 0) return;
        if(candidates[n-1] <= target){
            solve(candidates , target , store,vec,n-1);

            vec.push_back(candidates[n-1]);
            solve(candidates , target - candidates[n-1], store,vec,n);
            vec.pop_back();
        }else{
            solve(candidates , target , store,vec,n-1);
        }

    }
};