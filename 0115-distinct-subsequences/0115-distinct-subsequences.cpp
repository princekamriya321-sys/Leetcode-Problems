class Solution {
public:
vector<vector<int>> dp;
int solve(string &s1,int i,string &s2,int j){
    if(j < 0){ 
        return 1;
    }
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        int x = solve(s1,i-1,s2,j-1);
        int y = solve(s1,i-1,s2,j);
        return dp[i][j] = x+y;
    } else {
        int x = solve(s1,i-1,s2,j);
        return dp[i][j] = x;
    }
}
    int numDistinct(string s, string t) {
          int n = s.size();
        int m = t.size();
        dp.assign(n,vector<int>(m,-1));
        return solve(s,n-1,t,m-1);
    }
};