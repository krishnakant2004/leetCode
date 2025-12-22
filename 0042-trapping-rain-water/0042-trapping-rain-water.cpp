class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int totalWater = 0;
        int prev = 0;
        int next = 1;

        while(next < n){
            int deductArea = 0;
            while(next < n && height[next] < height[prev]){
                deductArea += height[next];
                next++;
            }
            if(next == n) break;
            
            totalWater += ((next - prev - 1) * height[prev]) - deductArea;
            prev = next;
            next++;
        }

        // traverse from last
        int limit = prev;
        prev = n-1;
        next = n-2;

        while(limit < next){
            int deductArea = 0;
            while(next > limit && height[next] < height[prev]){
                deductArea += height[next];
                next--;
            }
            totalWater += ((prev - next - 1) * height[prev]) - deductArea;
            prev = next;
            next--;
        }
        return totalWater;

    }
};