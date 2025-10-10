class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = energy.size();

        vector<int> st(n,0);
        int maxVal = INT_MIN;
        for(int i = n-1;i>=0;i--){
            int succ = i+k;
            st[i] = (succ >= n ? 0 : st[succ]) + energy[i];
            maxVal = max(maxVal , st[i]);
        }
        return maxVal;
    }
};