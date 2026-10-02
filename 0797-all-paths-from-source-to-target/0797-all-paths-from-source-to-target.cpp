class Solution {
public:
vector<vector<int>>arr;
int n;
void dfs(vector<vector<int>>& graph,vector<int> &ans,int src){
ans.push_back(src);
if(src == n-1) {
   arr.push_back(ans);
   return;
}
for(int v: graph[src]){
    dfs(graph,ans,v);
ans.pop_back();
}
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> ans;
        dfs(graph,ans,0);
        return arr;
    }
};