class Solution {
public:
vector<vector<int>>dp;
int solve(string& s,int i,int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]){
        if(i == j) return dp[i][j] = solve(s,i+1,j-1) + 1;
        return dp[i][j] = solve(s,i+1,j-1) + 2;
    } else {
        int x = solve(s,i+1,j);
        int y = solve(s,i,j-1);
        return dp[i][j] = max(x,y);
    }
}
    int longestPalindromeSubseq(string s) {
       int n = s.size();
       if(n == 1) return 1;
       dp.assign(n,vector<int>(n,-1)); 
       return solve(s,0,n-1);
    }
};