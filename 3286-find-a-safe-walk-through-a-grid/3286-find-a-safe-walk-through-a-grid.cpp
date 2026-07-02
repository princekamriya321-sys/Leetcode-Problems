class Solution {
public:
vector<vector<vector<int>>> dp;
bool solve(vector<vector<int>>& grid, int health,int i,int j,int n,int m){
    if(health == 0) return false;
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 2) return false;
    if(i == n-1 && j == m-1) {
        if(grid[i][j] == 1) {
            if(health <= 1) return false;
        }
        return true;
    }
    if(dp[i][j][health] != -1) return dp[i][j][health];
    if(grid[i][j] == 1){
           grid[i][j] = 2;
        bool a = solve(grid,health-1,i+1,j,n,m);
        bool b = solve(grid,health-1,i,j+1,n,m);
        bool c = solve(grid,health-1,i-1,j,n,m);
        bool d = solve(grid,health-1,i,j-1,n,m);
        grid[i][j] = 1;
       if(a || b || c|| d){
        return dp[i][j][health] = 1;
       } else {
        return dp[i][j][health] = 0;
       }
    } else {
           grid[i][j] = 2;
        bool a = solve(grid,health,i+1,j,n,m);
        bool b = solve(grid,health,i,j+1,n,m);
        bool c = solve(grid,health,i-1,j,n,m);
        bool d = solve(grid,health,i,j-1,n,m);
        grid[i][j] = 0;
         if(a || b || c|| d){
        return dp[i][j][health] = 1;
       } else {
        return dp[i][j][health] = 0;
       }
    }
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0; 
        int j = 0;
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(health+1,-1)));
      return  solve(grid,health,i,j,n,m);
    }
};