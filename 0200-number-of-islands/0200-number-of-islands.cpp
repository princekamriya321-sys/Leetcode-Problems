class Solution {
public:
void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int r,int c){
    vis[r][c] = true;
    if(r>0 && vis[r-1][c] == false && grid[r-1][c] == '1'){
        dfs(grid,vis,r-1,c);
    }
    if(r< grid.size()-1 && vis[r+1][c] == false && grid[r+1][c] == '1'){
        dfs(grid,vis,r+1,c);
    }
    if(c>0 && vis[r][c-1] == false && grid[r][c-1] == '1'){
        dfs(grid,vis,r,c-1);
    }
    if(c< grid[0].size()-1 && vis[r][c+1] == false && grid[r][c+1] == '1'){
        dfs(grid,vis,r,c+1);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ct = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    dfs(grid,vis,i,j);
                    ct++;
                }
            }
        }
        return ct;
    }
};