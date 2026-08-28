class Solution {
public:
bool solve(vector<vector<int>>& grid,int expectedval,int i,int j){
    int n= grid.size();
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != expectedval) return false;
    if( expectedval == n*n -1) return true;
 bool ans1 = solve(grid,expectedval+1,i-2,j+1);
  bool ans2 = solve(grid,expectedval+1,i-1,j+2);
   bool ans3 =  solve(grid,expectedval+1,i-2,j-1);
    bool ans4 =  solve(grid,expectedval+1,i-1,j-2);
    bool ans5 = solve(grid,expectedval+1,i+2,j+1);
     bool ans6 = solve(grid,expectedval+1,i+2,j-1);
    bool ans7 = solve(grid,expectedval+1,i+1,j+2);
    bool ans8 =  solve(grid,expectedval+1,i+1,j-2);
    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
}
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
      bool ans =  solve(grid,0,0,0);
        return ans;
    }
};