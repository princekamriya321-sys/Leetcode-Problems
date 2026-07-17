class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int maxDistance = distanceThreshold;
           vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
           for(int i = 0; i < n; i++) {
    adj[i][i] = 0;
}
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u][v] = wt;
             adj[v][u] = wt;
        }
        for(int k =0; k<n; k++){
            for(int u = 0; u<n; u++){
                for(int v = 0; v<n; v++){
                    if(adj[u][k] != INT_MAX &&  adj[k][v] != INT_MAX){
                        adj[u][v] = min(adj[u][v],adj[u][k] + adj[k][v]);
                    }
                }
            }
        }
        int ct = INT_MAX;
        int city = -1;
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if( adj[i][j]  != INT_MAX && adj[i][j] <= maxDistance){
                   count++;
                }
            }
           if(count <= ct){
               ct = count;
               city = max(i,city);
           }
        }
        return city; 
    }
};