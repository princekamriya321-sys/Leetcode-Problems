class Solution {
public:
    vector<int> low;
    vector<int> disc;
    vector<bool> vis;
    int timer = 0;
    vector<vector<int>> ans;
  void dfs(int n, vector<vector<int>>& graph,int src,int par){
      
        vis[src] = true;
        disc[src] = timer;
        low[src] = timer;
        timer++;
        for(auto nbr: graph[src]){
            if(nbr == par) continue;
            if(!vis[nbr]){
                dfs(n,graph,nbr,src);
            low[src] = min(low[src],low[nbr]);
                if(low[nbr] > disc[src]){
                    ans.push_back({src,nbr});
                }
            } else{
                low[src] = min(low[src],disc[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vis.assign(n,false);
      disc.assign(n,0);
      low.assign(n,0);
      vector<vector<int>> graph(n);
      for(int i=0; i<connections.size(); i++){
          int u = connections[i][0];
          int v = connections[i][1];
          graph[u].push_back(v);
          graph[v].push_back(u);
      }
      for(int i =0; i<n; i++){
          if(!vis[i]){
           dfs(n,graph,i,-1); 
          }
      }
 return ans;   
    }
};