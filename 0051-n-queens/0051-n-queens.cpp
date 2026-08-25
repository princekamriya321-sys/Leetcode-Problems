class Solution {
public:
vector<vector<string>>result;
bool isValid(vector<string>&board,int row,int col){
    int i = row;
    int j = col;
    while(i>=0){
        if(board[i][j] == 'Q') return false;
        i--;
    }
    i = row;
    j= col;
    while(i>=0 && j >=0){
        if(board[i][j] == 'Q') return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    while(i>=0 && j<board.size()){
        if(board[i][j] == 'Q') return false;
        i--;
        j++;
    }
    return true;
}
void solve(vector<string>&board,int row){
    if(row>=board.size()){
        result.push_back(board);
        return;
    }
    for(int col = 0; col<board.size(); col++){
        if(isValid(board,row,col)){
            board[row][col] = 'Q';
            solve(board,row+1);
            board[row][col] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
    return result;
    }
};