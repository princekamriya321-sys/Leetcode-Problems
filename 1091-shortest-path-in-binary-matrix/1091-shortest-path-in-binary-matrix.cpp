class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    if(n== 0 || m == 0 || grid[0][0] == 1) return -1;
        queue<pair<int,int>>q;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,1},{1,-1},{1,1},{-1,-1},{-1,0},{0,-1}};
    q.push({0,0});
    grid[0][0] = 1;
    int ct = 0;
    while(q.size()>0){
        int N = q.size();
            ct++;
        while(N--){
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if(x == n-1 && y == m-1) return ct;
        for(int i = 0; i<8; i++){
            int r = x + dir[i][0];
            int c = y + dir[i][1];
            if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == 1) continue;
            q.push({r,c});
            grid[r][c] = 1;
        }
        }
    }
    return -1;
    }
};