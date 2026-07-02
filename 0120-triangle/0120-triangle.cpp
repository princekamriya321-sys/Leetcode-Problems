class Solution {
public:
vector<vector<int>> dp;
vector<vector<bool>> vis;
int helper(vector<vector<int>>& triangle, int n,int i,int j){
    if(vis[i][j] != false) return dp[i][j];
    if(i==n || j > i) return 0;
    vis[i][j] = true;
    int x = helper(triangle,n,i+1,j) + triangle[i][j];
    int y = helper(triangle,n,i+1,j+1) + triangle[i][j];
    return dp[i][j] = min(x,y);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int i = 0; 
        int j = 0;
        dp.assign(n+1,vector<int>(n+1,-1));
        vis.assign(n+1,vector<bool>(n+1,false));
        return helper(triangle,n,i,j); 
    }
};