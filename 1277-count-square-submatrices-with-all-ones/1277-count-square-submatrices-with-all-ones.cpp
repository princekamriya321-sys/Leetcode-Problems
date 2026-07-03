class Solution {
public:
  vector<vector<int>>dp;
    int solve(vector<vector<int>> &cells,int n,int m,int i,int j){
        if(i<0 || j<0) return 0;
        if(i == n || j == m) return 0;
        if(cells[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int down = solve(cells,n,m,i+1,j);
        int diagonal = solve(cells,n,m,i+1,j+1);
        int right = solve(cells,n,m,i,j+1);
        return dp[i][j] = 1 + min({down,diagonal,right});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m =matrix[0].size();
        int ct = 0;
        dp.assign(n,vector<int>(m,-1));
        for(int i = 0;i<n; i++){
            for(int j = 0; j<m; j++){
               if(matrix[i][j] == 1){
                  ct += solve(matrix,n,m,i,j);
               }
            }
        }
        return ct;
    }
};