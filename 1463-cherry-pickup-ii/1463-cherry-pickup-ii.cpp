class Solution {
public:
 vector<vector<vector<int>>>dp;
int solve(vector<vector<int>> &grid,int n,int m,int i ,int j1,int j2){
      if(j1<0 || j1>=m || j2<0 || j2>=m)
            return -1e9;
   if(i == n) return 0;
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int grid_val = 0;
    if(j1 == j2){
        grid_val = grid[i][j1];
    } else {
        grid_val = grid[i][j1] + grid[i][j2];
    }
   int x1 = solve(grid,n,m,i+1,j1,j2);
   int x2 = solve(grid,n,m,i+1,j1-1,j2);
   int x3 = solve(grid,n,m,i+1,j1,j2-1);
   int x4 = solve(grid,n,m,i+1,j1-1,j2-1);
   int x5 = solve(grid,n,m,i+1,j1+1,j2);
   int x6 = solve(grid,n,m,i+1,j1,j2+1);
   int x7 = solve(grid,n,m,i+1,j1+1,j2+1);
   int x8 = solve(grid,n,m,i+1,j1-1,j2+1);
   int x9 = solve(grid,n,m,i+1,j1+1,j2-1);
   return dp[i][j1][j2] = max({x1,x2,x3,x4,x5,x6,x7,x8,x9}) + grid_val;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
    int m = grid[0].size();
     dp.assign(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(grid,n,m,0,0,m-1);
    }
};