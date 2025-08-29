class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        int mBy2 = m/2;
        for(int i = 1;i<=n;i++){
           if(i % 2 == 1){
                ans += mBy2;
           }else{
                if(m%2 == 0){
                    ans += mBy2;
                }else{
                    ans += (mBy2+1);
                }
           }
        }
        return ans;
    }
};