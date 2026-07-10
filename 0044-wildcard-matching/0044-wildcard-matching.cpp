class Solution {
public:
vector<vector<int>>dp;
bool solve(string &s,int i,string &p,int j){
    if(i == s.size() &&  j == p.size()) return true;
    if(j == p.size())
    return i == s.size();
    if(i == s.size())
{
    while(j < p.size())
    {
        if(p[j] != '*')
            return false;
        j++;
    }
    return true;
}
if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == p[j]){
        bool x  = solve(s,i+1,p,j+1);
        return dp[i][j] = x;
    } else if(p[j] == '?'){
        bool x = solve(s,i+1,p,j+1);
        return dp[i][j] = x;
    } else if(p[j] == '*'){
       bool x = solve(s,i,p,j+1);
       bool y = solve(s,i+1,p,j);
       if(x || y) {
           return dp[i][j] = true;
       } else {
           return dp[i][j] = false;
       }
    } else {
    return dp[i][j] = false;
    }
}
    bool isMatch(string s, string p) {
            dp.assign(s.size(),vector<int>(p.size(),-1));
        return solve(s,0,p,0);
    }
};