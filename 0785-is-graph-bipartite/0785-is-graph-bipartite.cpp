class Solution {
public:
bool helper(vector<vector<int>>&graph,vector<int>&vis,int i){
    queue<int> q;
    q.push(i);
    vis[i] = 10;
    while(q.size() > 0){
        int rem = q.front();
        q.pop();
        for(int v: graph[rem]){
        if(vis[v] == -1){
           if(vis[rem] == 10){
            vis[v] = 12;
           } else {
            vis[v] = 10;
           }
             q.push(v);
        } else {
            if(vis[rem] == vis[v]) return false;
        }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
     for(int i =0; i<n; i++){
        if(vis[i] == -1){
            bool t = helper(graph,vis,i);
            if(t == false) return false;
        }
     }
     return true;
    }
};