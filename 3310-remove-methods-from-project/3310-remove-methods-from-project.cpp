class Solution {
public:
// vector<int> ans;
void dfs(vector<vector<int>> &graph,vector<bool> &vis,int src){
    vis[src] = true;
    for(int& node: graph[src]){
        if(vis[node] == false){
            dfs(graph,vis,node);
        }
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n,false);
        for(int i =0; i<invocations.size(); i++){
         int u = invocations[i][0];
         int v = invocations[i][1];
         graph[u].push_back(v);
        }
        dfs(graph,vis,k);
        for(auto& t: invocations){
            int u = t[0];
            int v = t[1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i =0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i =0; i<n; i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};