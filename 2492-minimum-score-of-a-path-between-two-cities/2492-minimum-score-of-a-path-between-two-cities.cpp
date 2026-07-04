class Solution {
public: 
 int ans = INT_MAX;
 vector<vector<pair<int,int>>> graph;
 vector<int> vis;
void dfs(int node){
    vis[node] = 1;
    for(auto it: graph[node]){
        ans = min(ans,it.second);
     int next = it.first;
     if(!vis[next]){
        dfs(next);
     }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
       graph.resize(n+1);
       vis.assign(n+1,0);
        for(auto x : roads){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
          dfs(1);
        return ans;
    }
};