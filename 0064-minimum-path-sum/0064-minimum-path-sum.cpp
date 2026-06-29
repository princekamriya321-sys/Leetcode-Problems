class Solution {
public:
vector<vector<int>>dp;
int helper(vector<vector<int>> &grid,int i,int j){
    if(i == 0 && j == 0) return grid[0][0];
    if(i<0 || j< 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    int x = helper(grid,i-1,j);
    int y = helper(grid,i,j-1);
    return dp[i][j] = min(x,y) + grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
           int n = grid.size();
        int m =grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        int i =n-1;
        int j = m-1;
       return helper(grid,i,j);
    }
};