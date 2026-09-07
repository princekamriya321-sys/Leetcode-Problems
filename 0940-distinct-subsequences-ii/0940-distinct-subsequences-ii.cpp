class Solution {
public:
vector<int> dp;
vector<int>prev;
int mod = 1e9+7;
int solve(int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int total = (2*solve(n-1))%mod;
    if(prev[n]  != 0){
    int duplicates = solve(prev[n]-1);
    if(total - duplicates < 0){
        total = (total - duplicates + mod) % mod;
    } else {
    total = (total - duplicates)%mod;
    }
    }
    return dp[n] = total;
}
    int distinctSubseqII(string s) {
          int n = s.size();
        dp.assign(2001,-1);
        prev.assign(n+1,0);
        vector<int>lastseen(26,0);
        for(int i =1; i<=n; i++){
            int idx = s[i-1] -'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        return (solve(n) - 1 + mod) % mod;
    }
};