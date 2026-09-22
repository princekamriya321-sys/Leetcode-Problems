class Solution {
public:
vector<vector<int>>dp;
int solve(int m,int n,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n) return 0;
    if(i == m-1 && j == n-1){
        return 1;
    }
    if(dp[i][j] != -1)return dp[i][j];
        int x = solve(m,n,i+1,j);
        int y = solve(m,n,i,j+1);
        return dp[i][j] = x+y;
}
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        return solve(m,n,0,0);
    }
};