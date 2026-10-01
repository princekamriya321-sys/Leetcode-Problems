class Solution {
public:
void dfs(vector<vector<int>>&graph,vector<bool>&vis,int src){
    vis[src] = true;
    for(int u : graph[src]){
        if(vis[u] == false){
            dfs(graph,vis,u);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int ans = 0;
        for(int i =0; i<n; i++){
                if(vis[i] == false){
                    dfs(graph,vis,i);
                    ans++;
                }
        }
        return ans;
    }
};