class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        
        int l1 = s1.size();
        int l2 = s2.size();

        vector<int> repeatCount(n1+1,0);
        vector<int> nextIndex(n1+1,0);

        int count = 0;
        int j = 0;

        for(int i = 1;i<=n1;i++){

            for(int k = 0;k<l1;k++){
                if(s1[k] == s2[j]){
                    j++;
                    if(j == l2){
                        count++;
                        j = 0;
                    }
                }
            }
            repeatCount[i] = count;
                nextIndex[i] = j;
                            //check repetation
                for(int start = 0;start < i; start++){
                    if(nextIndex[start] == j){
                        int remain = n1 - start;
                        int patternCount = repeatCount[i] - repeatCount[start];
                        int pattenLen = i-start;

                        int t = remain / pattenLen;
                        int rest = remain % pattenLen;
                        return (repeatCount[start] + t*patternCount +(repeatCount[start+rest] - repeatCount[start])) / n2;
                    }
                }
        }
        return repeatCount[n1] / n2;
    }
};