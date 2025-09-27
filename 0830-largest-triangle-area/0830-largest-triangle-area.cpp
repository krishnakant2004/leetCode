class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double area = INT_MIN;
        int n = p.size();

        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    double res = abs( (p[j][0]-p[i][0]) * (p[k][1]-p[i][1]) - (p[j][1] - p[i][1]) * (p[k][0] - p[i][0]) ) * 0.5;
                    area = max(res, area);
                }
            }
        }
        return std::round(area * 100000)/100000;
    }

   
};