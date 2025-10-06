class Solution {
public:
    vector<vector<int>> route = {{0,1},{0,-1},{1,0},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        return distkraj(grid);
        return solve(grid,0,0);
    }

    int solve(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1) return grid[i][j];
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) return INT_MAX;

        int dist = INT_MAX;
        int curr = grid[i][j];
        grid[i][j] = -1;
        for(auto const &vec : route){
            int Ni = i + vec[0];
            int Nj = j + vec[1];
            dist = min(dist , solve(grid,Ni,Nj));
        }
        grid[i][j] = curr;
        return max(curr , dist);
    }

int distkraj(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    vector<vector<int>> route = {{1,0},{-1,0},{0,1},{0,-1}};

    // Min-heap based on distance
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
    pq.push({grid[0][0], {0,0}});
    dist[0][0] = grid[0][0];

    while(!pq.empty()) {
        auto [val, p] = pq.top();
        auto [i, j] = p;
        pq.pop();

        if (vis[i][j]) continue;
        vis[i][j] = true;

        for (auto const &d : route) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            int newVal = max(val, grid[ni][nj]);
            if (newVal < dist[ni][nj]) {
                dist[ni][nj] = newVal;
                pq.push({newVal, {ni, nj}});
            }
        }
    }

    return dist[n-1][m-1];
}

};