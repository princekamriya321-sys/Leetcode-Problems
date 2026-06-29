class Solution {
public:
vector<vector<int>>dp;
int helper(string &s1,int i,string &s2,int j){
   if(i == -1 && j == -1) return 0;
   if(i == -1 && j != -1) return j+1;
   if(i != -1 && j == -1) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        int x = helper(s1,i-1,s2,j-1);
        return dp[i][j] = x;
    } else{
        int x = helper(s1,i-1,s2,j);
        int y = helper(s1,i,s2,j-1);
        return dp[i][j] = min(x,y) + 1;
    }
}
    int minDistance(string word1, string word2) {
        string s1 = word1;
        string s2 = word2;
        int n = s1.size();
        int m = s2.size();
        int i = n-1;
        int j = m-1;
        dp.assign(n,vector<int>(m,-1));
        return helper(s1,i,s2,j);
    }
};