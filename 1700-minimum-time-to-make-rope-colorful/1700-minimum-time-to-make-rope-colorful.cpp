class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
         int maxEle = neededTime[0];
        for(int i = 1;i<colors.size();i++){
            if(colors[i-1] == colors[i]){
               time += min(maxEle , neededTime[i]);
               maxEle = max(maxEle , neededTime[i]);
            }else{
                maxEle = neededTime[i];
            }
           
        }
        return time;
    }
};