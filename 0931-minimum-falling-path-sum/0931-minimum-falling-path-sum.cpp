class Solution {
public:
int n;
vector<vector<int>>dp;
int solve(vector<vector<int>>& matrix,int i,int j){
    if(i == n-1) return matrix[i][j];
    if(dp[i][j] != INT_MAX) return dp[i][j];
    int ans = INT_MAX;
    if(j-1>=0){
         ans =min(ans,solve(matrix,i+1,j-1));
    }
         ans = min(ans,solve(matrix,i+1,j));
    if(j+1 < n){
        ans = min(ans,solve(matrix,i+1,j+1));
    }
    return dp[i][j] = ans + matrix[i][j];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n = matrix.size();
         int sum = 0;
         dp.assign(n+1,vector<int>(n+1,INT_MAX));
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
       ans = min(ans,solve(matrix,0,j));
        }
        return ans;
    }
};