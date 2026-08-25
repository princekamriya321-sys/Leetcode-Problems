class Solution {
public:
bool solve(vector<vector<char>>& board, string word,vector<vector<bool>>&vis,int i,int j,int k){
    if(i<0 || i>= board.size()|| j<0 || j>=board[0].size()) return false;
    if(board[i][j] != word[k] || vis[i][j])
    return false;
    if(k == word.size()-1)
    return true;
    if(board[i][j] == word[k] && vis[i][j] == false) {
         vis[i][j] = true;
        bool a = solve(board,word,vis,i+1,j,k+1);
        bool b = solve(board,word,vis,i,j+1,k+1);
        bool c = solve(board,word,vis,i-1,j,k+1);
        bool d = solve(board,word,vis,i,j-1,k+1);
        vis[i][j] = false;
        if(a || b|| c|| d) return true;
    } 
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i= 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j] == word[0]){
                    bool ans = solve(board,word,vis,i,j,0); 
                    if(ans == true) return true;
                }
            }
        }
        return false;
    }
};