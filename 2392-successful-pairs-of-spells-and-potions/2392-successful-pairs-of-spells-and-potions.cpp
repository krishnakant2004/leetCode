class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int pSize = potions.size();
        sort(potions.begin(),potions.end());

        vector<int> st(n,0);
        for(int i = 0;i<n;i++){
            int idx = getIdx(potions,spells[i],success,0,pSize-1);
            st[i] = pSize - idx;
        }
        return st;
    }

    int getIdx(vector<int>& potions,int &spell,long long &success,int l,int r){
        if(l > r){
            return l;
        }

        int mid = l + (r-l)/2;

        long long prod = (long long)potions[mid] * spell;
        if(prod < success){
            return getIdx(potions,spell,success,mid+1,r);
        }else{
            return getIdx(potions,spell,success,l,mid-1);
        }
    }
};