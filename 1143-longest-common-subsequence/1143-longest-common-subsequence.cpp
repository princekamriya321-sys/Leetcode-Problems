class Solution {
public:
vector<vector<int>>dp;
int solve(string &s1,int i,string &s2,int j){
    if(i >= s1.size() || j>= s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        int x = solve(s1,i+1,s2,j+1) + 1;
        return dp[i][j]= x;
    } else {
        int x = solve(s1,i+1,s2,j);
        int y = solve(s1,i,s2,j+1);
        return dp[i][j] = max(x,y);
    }
}
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size();
      int m = text2.size();
     dp.assign(n+1,vector<int>(m+1,-1));
     return solve(text1,0,text2,0);
    }
};