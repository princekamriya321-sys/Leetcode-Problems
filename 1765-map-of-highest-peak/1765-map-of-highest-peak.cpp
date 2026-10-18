class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(mat[i][j] == 1){
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }
        while(q.size() > 0){
        auto idx = q.front();
        q.pop();
        int i = idx.first;
        int j = idx.second;
        if(i-1>=0 && result[i-1][j] == -1){
            result[i-1][j] = result[i][j] + 1;
            q.push({i-1,j});
        }
        if(i+1<n && result[i+1][j] == -1){
            result[i+1][j] = result[i][j] + 1;
            q.push({i+1,j});
        }
        if(j-1>=0 && result[i][j-1] == -1){
            result[i][j-1] = result[i][j] + 1;
            q.push({i,j-1});
        }
        if(j+1<m && result[i][j+1] == -1){
            result[i][j+1] = result[i][j] + 1;
            q.push({i,j+1});
        }
        }
        return result;
    }
};