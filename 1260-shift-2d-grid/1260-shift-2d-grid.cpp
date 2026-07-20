class Solution {
public:
void func(vector<vector<int>>&grid){
     int n = grid.size();
     int m = grid[0].size();
     vector<vector<int>> ans(n,vector<int>(m));
     ans[0][0] = grid[n-1][m-1];
     for(int i = 0; i<n; i++){
        if(i != 0){
        ans[i][0] = grid[i-1][m-1];
        }
        for(int j = 1; j<m; j++){
            ans[i][j] = grid[i][j-1];
        }
     }
     for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            grid[i][j] = ans[i][j];
        }
     }

}
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ct = 0;
        while(ct< k){
            ct++;
        func(grid);
        }
        return grid;
    }
};