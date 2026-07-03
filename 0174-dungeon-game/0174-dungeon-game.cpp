class Solution {
public:
vector<vector<int>>dp;
int solve(vector<vector<int>> &dungeon,int n,int m,int i ,int j){
    if(i == n || j == m) return 1e9;
    if(i == n-1 && j == m-1){
        if(dungeon[i][j] > 0) return 1;
        else 
        return abs(dungeon[i][j]) + 1;
        }
    if(dp[i][j] != -1) return dp[i][j];
    int right = solve(dungeon,n,m,i,j+1);
    int down = solve(dungeon,n,m,i+1,j);
    int result = min(right,down) - dungeon[i][j];
    if(result > 0){
        return dp[i][j] = result;
    } else {
        return dp[i][j] = 1;
    }
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solve(dungeon,n,m,0,0);
    }
};