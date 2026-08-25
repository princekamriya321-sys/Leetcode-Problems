class Solution {
public:
int ans = 0;
void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int row,int col){
    if(row<0 || row >=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] == '0' || vis[row][col]== true) return;
    vis[row][col] = true;
    dfs(grid,vis,row+1,col);
    dfs(grid,vis,row-1,col);
    dfs(grid,vis,row,col+1);
    dfs(grid,vis,row,col-1);
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    dfs(grid,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};