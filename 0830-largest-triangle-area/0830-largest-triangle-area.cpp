class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = INT_MIN;
        int n = points.size();

        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    area = max(area , getArea(points[i],points[j],points[k]));
                }
            }
        }
        return area;
    }

    double getArea(vector<int>& a,vector<int>& b,vector<int>& c){
        double lenA = sqrt(pow(b[0] - a[0],2) + pow(b[1] - a[1],2));
        double lenB = sqrt(pow(c[0] - a[0],2) + pow(c[1] - a[1],2));
        double lenC = sqrt(pow(c[0] - b[0],2) + pow(c[1] - b[1],2));
        double s = (lenA + lenB + lenC)/2;

        double A = sqrt(s*(s - lenA)*(s-lenB)*(s-lenC));
        return std::round(A * 100000)/100000;
    }
};