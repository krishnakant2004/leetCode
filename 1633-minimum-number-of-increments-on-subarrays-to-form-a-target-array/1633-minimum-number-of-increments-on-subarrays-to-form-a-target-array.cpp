class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        for(int i = 1;i<target.size();i++){
            res += max(0 , target[i] - target[i-1]);
        }
        return res;
        
        return solve(target,0,target.size()-1);
    }

    int solve(vector<int>& target,int l,int r){
        if(l > r) return 0;

        int minele  = INT_MAX;
        for(int i = l;i<=r;i++) minele = min(minele , target[i]);
        int count = minele;
        int previdx = l;

        for(int i = l ; i <= r ; i++){
            if(target[i] == minele){
                count += solve(target,previdx , i-1);
                previdx = i+1;
            }
            if(i == r && target[i] != minele){
                target[i] -= minele;
                count += solve(target,previdx , i);
            }
            target[i] -= minele;
        }
        return count;
    }
};

