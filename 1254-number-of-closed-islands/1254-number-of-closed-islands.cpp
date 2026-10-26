class Solution {
public:
int n,m;
bool solve(vector<vector<int>>& grid,int i,int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    if(grid[i][j]==1) return true;
    grid[i][j] = 1;
       bool up = solve(grid, i - 1, j);
        bool down = solve(grid, i + 1, j);
        bool left = solve(grid, i, j - 1);
        bool right = solve(grid, i, j + 1);

        return up && down && left && right;
}
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ct = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 0){
                    bool ans = solve(grid,i,j);
                    if(ans) ct++;
                }
            }
        }
        return ct;
    }
};