class Solution {
public:
int ans= 0;
 void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j){
    vis[i][j] = true;
    if(i>0 && vis[i-1][j] == false && grid[i-1][j] == 1){
       dfs(grid,vis,i-1,j);
    }
    if(j>0 && vis[i][j-1] == false && grid[i][j-1] == 1){
        dfs(grid,vis,i,j-1);
    }
     if(i<grid.size()-1 && vis[i+1][j] == false && grid[i+1][j] == 1){
         dfs(grid,vis,i+1,j);
    }
     if(j<grid[0].size() && vis[i][j+1] == false && grid[i][j+1] == 1){
          dfs(grid,vis,i,j+1);
    }
}
 void dfs2(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j){
     ans++;
    vis[i][j] = true;
    if(i>0 && vis[i-1][j] == false && grid[i-1][j] == 1){
       dfs2(grid,vis,i-1,j);
    }
    if(j>0 && vis[i][j-1] == false && grid[i][j-1] == 1){
        dfs2(grid,vis,i,j-1);
    }
     if(i<grid.size()-1 && vis[i+1][j] == false && grid[i+1][j] == 1){
         dfs2(grid,vis,i+1,j);
    }
     if(j<grid[0].size() && vis[i][j+1] == false && grid[i][j+1] == 1){
          dfs2(grid,vis,i,j+1);
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
          int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ct = 0;
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == false && grid[i][j] == 1 && (i == 0 || i== n-1 || j == 0 || j == m -1)){
                  dfs(grid,vis,i,j);
                }
            }
        }
          for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == false && grid[i][j] == 1){
                  dfs2(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};