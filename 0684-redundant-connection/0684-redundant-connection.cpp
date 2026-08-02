class Solution {
public:
vector<int> par;
vector<int> rank;
int find(int x){
    if(par[x] == x) return x;
    int temp = find(par[x]);
    par[x] = temp;
    return temp;
}
bool Union(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return false;;
    if(rank[px] > rank[py]){
        par[py] = px;
    } else if(rank[px] < rank[py]){
        par[px] = py;
    } else{
        par[px] = py;
        rank[px]++;
    }
    return true;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // vector<vector<int>> graph(n+1);
        // for(int i =0; i<n; i++){
        //  int u = edges[i][0];
        //  int v = edges[i][1];
        //  graph[u].push_back(v);
        //  graph[v].push_back(u);
        // }
        par.resize(n + 1);
        rank.assign(n + 1, 0);
        for(int i = 0; i <= n; i++){
    par[i] = i;
    rank[i] = 1;
}
        int x = 0;
        int y= 0;
      for(int i = 0; i<n; i++){
       int u =  edges[i][0];
       int v = edges[i][1];
       if(Union(u,v) == false){
        x = u;
        y = v;
       }
      }
      return {x,y};
    }
};