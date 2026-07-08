class Solution {
public:
class Pair{
    public:
    int row;
    int col;
    int time;
    Pair(int r,int c,int t){
        row = r;
        col =c;
        time =t;
    }
};
vector<vector<int>> bfs(vector<vector<int>>&grid,int n,int m){
vector<vector<int>> ans(n,vector<int>(m,-1));
queue<Pair>q;
vector<vector<bool>>vis(n,vector<bool>(m,false));
for(int i = 0; i<n; i++){
   for(int j =0; j<m; j++){
       if(grid[i][j] == 0){
           q.push(Pair{i,j,0});
       }
   }
}

while(q.size()>0){
    auto rem = q.front();
    q.pop();
    int r = rem.row;
    int c = rem.col;
    int t = rem.time;
    if(ans[r][c] == -1){
        ans[r][c] = t;
        vis[r][c] = true;
    }
    if(r>0 && vis[r-1][c] == false){
        q.push({r-1,c,t+1});
    }
    if(c>0 && vis[r][c-1] == false){
        q.push({r,c-1,t+1});
    }
    if(r<n-1 && vis[r+1][c] == false){
        q.push({r+1,c,t+1});
    }
    if(c<m-1 && vis[r][c+1] == false){
        q.push({r,c+1,t+1});
    }
}
return ans;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
          int n = mat.size();
    int m = mat[0].size();
     return bfs(mat,n,m); 
    }
};