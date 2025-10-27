class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int prev = 0;
       
        for(int  i = 0;i<bank.size();i++){
            int curr = 0;
            for(int j = 0;j<bank[0].size();j++){
                if(bank[i][j] == '1') curr += 1;
            }
            if(curr > 0 && prev == 0){
                prev = curr;
                continue;
            }
            if(curr > 0){
                count += prev * curr;
                prev = curr;
            }
        }
        return count;
    }
};