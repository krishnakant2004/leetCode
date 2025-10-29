class Solution {
public:
    int smallestNumber(int n) {
        int sum = 0;
        int val = n;
        int i = 0;
        while(val){
            if(!(val & 1)) n = n | (1<<i);
            val >>= 1;
            i++;
        }
     return n;   
    }
};