class Solution {
public:
int n,m;
int mod = 1e9+7;
vector<vector<vector<long long>>>dp;
long long solve(vector<vector<int>>& grid,int i,int j,int camefrom){
    if(i<0 || i>=n || j<0 || j>= m) return 0;
    if(i == n-1 && j == m-1){
        return 1;
    }
    if(dp[i][j][camefrom] !=-1) return dp[i][j][camefrom]%mod;
    if(grid[i][j] == 1){
        if(camefrom == 0){
        return dp[i][j][camefrom] = solve(grid,i+1,j,1)%mod;
        } else {
            return dp[i][j][camefrom] = solve(grid,i,j+1,0)% mod;
        }
    } else {
        long long x = solve(grid,i+1,j,1);
        long long y = solve(grid,i,j+1,0);
        return dp[i][j][camefrom] = (x+y)%mod;
    }
}
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(2,-1)));
        int ans = solve(grid,0,0,0);
        return ans;
    }
};