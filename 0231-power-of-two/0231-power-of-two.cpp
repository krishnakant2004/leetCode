class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        if(n <= 0) return false;

        while(n){
           if(n & 1 == 1 && n > 1) return false;
           n = n>>1;
        }
        return true;
       
    }
};