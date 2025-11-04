class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
         priority_queue<int, vector<int>, greater<int>> pq;
         pq.push(neededTime[0]);
        for(int i = 1;i<colors.size();i++){
            if(colors[i-1] == colors[i]){
               pq.push(neededTime[i]);
            }
            if(colors[i-1] != colors[i] || i == colors.size()-1){
                while(!pq.empty()){
                    if(pq.size() > 1){
                        time += pq.top();
                    }
                    pq.pop();
                }
                pq.push(neededTime[i]);
            }
        }
        return time;
    }
};