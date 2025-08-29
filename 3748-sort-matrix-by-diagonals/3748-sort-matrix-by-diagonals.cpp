class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int len = grid.size();
        int n = len;
        int row = len-1;
        int col = 0;

        while(row >= 0 && col < len){
            int i = row;
            int j = 0;
            vector<int> vec;
            while(i < len && j <= col){
                vec.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(vec.begin(),vec.end(),greater<int>());

            int p = 0;
            i = row;
            j = 0;
            while(i < len && j <= col){
                grid[i][j] = vec[p];
                p++;
                i++;
                j++;
            }
            row--;
            col++;
        }

        row = len-2;
        col = 1;
        while(col < n && row >= 0){
            int i = 0;
            int j = col;
            vector<int> vec;
            while(i <= row && j < n){
                vec.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(vec.begin(),vec.end());
            int p = 0;
            i = 0;
            j = col;
            while(i <= row && j < n){
                grid[i][j] = vec[p];
                p++;
                i++;
                j++;
            }
            col++;
            row--;
        }
        return grid;

       
    }
};