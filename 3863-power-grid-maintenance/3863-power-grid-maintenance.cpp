class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& conn, vector<vector<int>>& queries) {
        int n = c;
        vector<vector<int>> graph(n+1);
        for(int i = 0;i<conn.size();i++){
            graph[conn[i][0]].push_back(conn[i][1]);
            graph[conn[i][1]].push_back(conn[i][0]);
        }
        unordered_map<int,int> ref;
        unordered_map<int,priority_queue< int, vector<int>, greater<int>>> sep_graph;
        vector<int> visited(n+1,-1);

        for(int i = 1; i<=n;i++){
            if(visited[i] == -1){
                makeVec(graph, visited,sep_graph , ref ,i,i);
            }
        }


        // queries
        //for operational
        for(int i = 0;i<=n;i++){
            visited[i] = 1;
        }
        vector<int> ans;

        for(auto const &q : queries){
            if(q[0] == 1){
                int temp = -1;
                if(visited[q[1]]){
                    temp = q[1];
                }else if(!sep_graph[ref[q[1]]].empty()){
                    while(!sep_graph[ref[q[1]]].empty() && visited[sep_graph[ref[q[1]]].top()] == 0){
                        sep_graph[ref[q[1]]].pop();
                    }
                    if(!sep_graph[ref[q[1]]].empty()){
                        temp = sep_graph[ref[q[1]]].top();
                    }
                }
                ans.push_back(temp);
            }if(q[0] == 2){
                visited[q[1]] = 0;
            }
        }
        return ans;
    }

    void makeVec(vector<vector<int>> &graph, vector<int> &visited, unordered_map<int,priority_queue< int, vector<int>, greater<int>>> &sep_graph , unordered_map<int,int> &node_ref_vec,int curr_node,int ref){

        if(visited[curr_node] != -1) return;
        visited[curr_node] = 1;
        node_ref_vec[curr_node] = ref;
        sep_graph[ref].push(curr_node);
        
        for(auto &ele : graph[curr_node]){
            makeVec(graph , visited , sep_graph ,  node_ref_vec , ele , ref);
        }
    }
};