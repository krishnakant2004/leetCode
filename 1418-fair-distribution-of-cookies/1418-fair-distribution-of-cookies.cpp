class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        int n = cookies.size();
        vector<int> dst(k+1,0);
        solve(cookies,dst,k,ans,n);
        return ans;
    }

    void solve(vector<int>& cookies,vector<int> &dst,int &k,int &ans,int n){
        if(n == 0){
            ans = min( ans , *max_element(dst.begin(),dst.end()) );
            return;
        }

        for(int i = 1;i<=k;i++){
            dst[i] += cookies[n-1];
            solve(cookies,dst,k,ans,n-1);
            dst[i] -= cookies[n-1];
        }
    }

};