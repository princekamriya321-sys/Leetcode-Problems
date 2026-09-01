class Solution {
public:
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VVVVB = vector<VVVB>;
vector<vector<int>> directions = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
struct State{
    int row;
    int col;
    int energyLeft;
    int collectedMask;
};
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int maxenergy = energy;
        int letterbit[20][20];
        int lettercount = 0;
        int startR = 0;
        int startC = 0;
        for(int r = 0; r<n; r++){
            for(int c = 0;  c<m; c++){
                letterbit[r][c] = -1;
                if(classroom[r][c] == 'S'){
                    startR = r;
                    startC  = c;
                } else if(classroom[r][c] == 'L'){
                    letterbit[r][c] = lettercount;
                    lettercount++;
                }
            }
        }
     int allcollected = (1<<lettercount)-1;
     if(lettercount == 0) return 0;
     queue<State> q;
    VVVVB visited(n,VVVB(m,VVB(maxenergy+1,VB(1<<lettercount,false))));
     q.push({startR,startC,maxenergy,0});
     visited[startR][startC][maxenergy][0] = true;
     int moves = 0;
     while(q.size() > 0){
        int size = q.size();
        while(size--){
        State curr = q.front();
        q.pop();
        if(curr.collectedMask == allcollected) return moves;
        if(curr.energyLeft == 0) continue;
        for(auto& dir: directions){
            int nextR = dir[0] + curr.row;
            int nextC = dir[1] + curr.col;
            if(nextR <0 || nextR >=n || nextC<0 || nextC >=m)continue;
            char cell = classroom[nextR][nextC];
            if(cell == 'X')continue;
            int nextEnergy = curr.energyLeft -1;
            int nextCollectMask = curr.collectedMask;
             if(cell == 'R'){
                nextEnergy = maxenergy;
             } else if(cell == 'L'){
              nextCollectMask |= (1<<letterbit[nextR][nextC]);
             }
             if(!visited[nextR][nextC][nextEnergy][nextCollectMask]){
                q.push({nextR,nextC,nextEnergy,nextCollectMask});
                visited[nextR][nextC][nextEnergy][nextCollectMask] = true;
             }
        }
        }
        moves++;
     }
     return -1;
    }
};