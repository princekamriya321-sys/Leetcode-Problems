class Solution {
public:
vector<vector<vector<int>>>dp;
int solve(string &s,int i,int tight,int ct){
    if(i == s.size()) return ct;
    if(dp[i][tight][ct] != -1) return dp[i][tight][ct];
    int limit = (tight == 1? s[i]-'0' : 9);
    int ans = 0;
    for(int j = 0; j<=limit; j++){
        int updct = ct + (j == 1 ? 1 : 0);
        ans += solve(s,i+1,(tight && (limit == j)),updct);
    }
    return dp[i][tight][ct] = ans;
}
    int countDigitOne(int n) {
        string s = to_string(n);
        dp.assign(13,vector<vector<int>>(2,vector<int>(13,-1)));
        return solve(s,0,1,0);
    }
};