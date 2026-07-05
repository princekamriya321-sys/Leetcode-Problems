class Solution {
public:
int mod = 1e9+7;
vector<int>ans;
    vector<vector<pair<int,int>>> dp;
    vector<vector<bool>> vis;
pair<int,int> solve(vector<string>& board,int i,int j){
if(i<0 || j<0) return {-1e9,0};
if(board[i][j] == 'X'){
    return {-1e9,0};
}
    if(i == 0 && j == 0)
            return {0,1};

        if(vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        auto up = solve(board,i-1,j);
        auto left = solve(board,i,j-1);
        auto diag = solve(board,i-1,j-1);

        int best = max({up.first,left.first,diag.first});

        if(best < 0)
        {
            dp[i][j] = {-1000000000,0};
            return dp[i][j];
        }

        long long ways = 0;

        if(up.first==best)
            ways = (ways + up.second)%mod;

        if(left.first==best)
            ways = (ways + left.second)%mod;

        if(diag.first==best)
            ways = (ways + diag.second)%mod;

        int value = 0;

        if(board[i][j]>='0' && board[i][j]<='9')
            value = board[i][j]-'0';

        dp[i][j] = {best+value,(int)ways};

        return dp[i][j];
}
    vector<int> pathsWithMaxScore(vector<string>& board) {
      int n = board.size();

        dp.assign(n,vector<pair<int,int>>(n));
        vis.assign(n,vector<bool>(n,false));

        pair<int,int> ans = solve(board,n-1,n-1);

        if(ans.second==0)
            return {0,0};

        return {ans.first,ans.second};
    }
};