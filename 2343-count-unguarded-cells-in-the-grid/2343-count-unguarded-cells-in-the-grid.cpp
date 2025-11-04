class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(n , vector<int>(m,0));

        for(auto const &w : walls){
            mat[w[0]][w[1]] = 2;
        }
        for(auto const &w : guards){
            mat[w[0]][w[1]] = 3;
        }

        for(auto const &p : guards){
            //right
            
            int i = p[0];
            int j = p[1]+1;

            while(j < m && mat[i][j] != 2 && mat[i][j] != 3){
                mat[i][j] = 1;
                j++;
            }
            //left
            i = p[0];
            j = p[1]-1;
            while(j >= 0 && mat[i][j] != 2 && mat[i][j] != 3){
                mat[i][j] = 1;
                j--;
            }
            //up
            i = p[0]-1;
            j = p[1];
            while( i >= 0 && mat[i][j] != 2 && mat[i][j] != 3){
                mat[i][j] = 1;
                i--;
            }
            //down
            i = p[0] + 1;
            j = p[1];
            while( i < n && mat[i][j] != 2 && mat[i][j] != 3){
                mat[i][j] = 1;
                i++;
            }
        }

        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0) count++;
            }
        }
        return count;
    }
};