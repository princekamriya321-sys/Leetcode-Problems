class Solution {
public:
vector<vector<int>> dp;
int solve(string&s1,int i,string &s2,int j){
    if(i == s1.size() && j == s2.size()) return 0;
    if(i != s1.size() && j == s2.size()){
        return s1.size() - i;
    }
    if(i == s1.size() && j != s2.size()) return s2.size() - j;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
    return dp[i][j] = solve(s1,i+1,s2,j+1);
    } else {
        int x = solve(s1,i,s2,j+1);
        int y = solve(s1,i+1,s2,j);
        int z = solve(s1,i+1,s2,j+1);
        return dp[i][j] = min({x,y,z}) + 1;
    }
}
    int minDistance(string word1, string word2) {
       int n = word1.size();
       int m = word2.size();
       dp.assign(n,vector<int>(m,-1));
       return solve(word1,0,word2,0); 
    }
};