class Solution {
public:
void dfs(vector<vector<char>> &grid,vector<vector<bool>> &vis,int i,int j){
    vis[i][j] = true;
    vector<int> dr= {-1,0,1,0};
    vector<int> dc={0,-1,0,1};
    int n = grid.size();
    int m = grid[0].size();
    for(int k = 0; k<4; k++){
        int r = dr[k] + i;
        int c = dc[k] + j;
        if(r <0 || r >= n-1 || c < 0 || c >=m-1) continue;
            if(grid[r][c] == 'O' && vis[r][c] == false){
                dfs(grid,vis,r,c);
            }
        }
    
}
    void solve(vector<vector<char>>& board) {
          int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == false && board[i][j] == 'O' && (i == 0 || j== 0 || i == n-1 || j== m-1)){
                    dfs(board,vis,i,j);
                }
            }
        }
          for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == false && board[i][j] == 'O'){
                   board[i][j] = 'X';
                }
            }
        }
    }
};