class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> store;
        vector<int> vec;
        // solve(candidates , target , store,vec,n);
        solve2(candidates , target , store,vec,1);
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

    void solve2(vector<int>& can, int target , vector<vector<int>> &store,vector<int>& vec,int i){
        if(target == 0){
            store.push_back(vec);
            return;
        }

        for(int j = i;j<=can.size();j++){
            if(j > i && can[j-1] == can[j-2]) continue;
            if(target >= can[j-1]){
                vec.push_back(can[j-1]);
                solve2(can,target-can[j-1] , store,vec,j);
                vec.pop_back();
            }
                
        }
    }
};