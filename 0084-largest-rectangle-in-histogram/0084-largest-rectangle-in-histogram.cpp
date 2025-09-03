class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long largestArea =  INT_MIN;
        stack<pair<int,int>> stk; //index,height
        int n = heights.size();

//from left to right
        for(int i = 0;i<n;i++){
            int newIdx = i;
            while(!stk.empty()){
                pair<int,int> t = stk.top();
                if(t.second <= heights[i])break;

                largestArea = max(largestArea , (1LL)*(i - t.first)*t.second);
                newIdx = t.first;
                stk.pop();
            }
            stk.push({newIdx,heights[i]});
        }
        while(!stk.empty()){
            pair<int,int> t = stk.top();
            largestArea = max(largestArea , (1LL)*(n - t.first)*t.second);
            stk.pop();
        }
// //from right to left
//         for(int i = n-1;i>=0;i--){
//             int newIdx = i;
//             while(!stk.empty()){
//                 pair<int,int> t = stk.top();
//                 if(t.second <= heights[i])break;
//                 largestArea = max(largestArea , (1LL)*(t.first - i)*t.second);
//                 newIdx = t.first;
//                 stk.pop();
//             }
//             stk.push({newIdx,heights[i]});
//         }
//         while(!stk.empty()){
//             pair<int,int> t = stk.top();
//             largestArea = max(largestArea , (1LL)*(t.first + 1)*t.second);
//             stk.pop();
//         }
    return largestArea;
    }
};