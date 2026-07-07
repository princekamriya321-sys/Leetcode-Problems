class Solution {
public:
class Pair{
 public:
 int i;
 int j;
 int time;
 Pair(int x1,int x2,int t){
     i = x1;
     j = x2;
     time =t;
 }
};
    int orangesRotting(vector<vector<int>>& grid) {
              int ans = 0;
        queue<Pair> q;
      int n = grid.size();
      int m = grid[0].size();
      for(int i =0; i<n; i++){
          for(int j =0; j<m; j++){
              if(grid[i][j] == 2){
                  q.push({i,j,0});
              }
          }
      }
        while(q.size()>0){
            auto rem = q.front();
            q.pop();
            int row = rem.i;
            int col = rem.j;
            int ctime = rem.time;
            ans = ctime;
            if(row>0 && grid[row-1][col] == 1){
                q.push(Pair{row-1,col,ctime+1});
                grid[row-1][col] = 2;
            }
                if(col>0 && grid[row][col-1] == 1){
                q.push(Pair{row,col-1,ctime+1});
                grid[row][col-1] =2;
            }
                if(row<n-1 && grid[row+1][col] == 1){
                q.push(Pair{row+1,col,ctime+1});
                grid[row+1][col] = 2;
            }
                if(col<m-1 && grid[row][col+1] == 1){
                q.push(Pair{row,col+1,ctime+1});
                grid[row][col+1] = 2;
            }
        }
        for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1)
            return -1;
    }
}
        return ans;
    }
};