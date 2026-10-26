class Solution {
public:
int n,m;
long long solve(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0 || vis[i][j] == true) return 0;
    vis[i][j] = true;
    long long up = solve(grid,vis,i-1,j);
    long long down = solve(grid,vis,i+1,j);
   long long left = solve(grid,vis,i,j-1);
    long long right = solve(grid,vis,i,j+1);
    return (up + down + left + right) + grid[i][j];
}
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ct =0;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(vis[i][j] == false&& grid[i][j] != 0){
               long long sum = solve(grid,vis,i,j);
               if(sum%k == 0) ct++;
            } 
        }
    }
return ct;
    }
};