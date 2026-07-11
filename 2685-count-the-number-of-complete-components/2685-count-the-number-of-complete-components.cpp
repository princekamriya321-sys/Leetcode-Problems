class Solution {
public:
void dfs(int n,vector<vector<int>>&graph,vector<bool> &vis,int src,vector<int>&comp){
    vis[src] = true;
    comp.push_back(src);
    for(int v : graph[src]){
     if(vis[v] == false){
        dfs(n,graph,vis,v,comp);
     }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
      vector<bool> vis(n,false);
      int ans = 0;
      for(int i = 0; i<n; i++){
       if(vis[i] == false){
        vector<int> comp;
        dfs(n,graph,vis,i,comp);
    int degreeSum = 0;
     for(int node : comp){
    degreeSum += graph[node].size();
     }
    int edges = degreeSum / 2;
    int m = comp.size();
    if(edges == m*(m-1)/2){
        ans++;
    }
}
      }
      return ans;
    }
};