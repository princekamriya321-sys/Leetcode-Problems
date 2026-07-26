class Solution {
public:
vector<vector<vector<vector<long long>>>>dp;
    int k;
    string s;
    long long dfs(int i,int prev,int tight,int started){
        if(i == s.size()){
            return started;
        }
        if(dp[i][prev+1][tight][started] != -1){
            return dp[i][prev+1][tight][started];
        }
        int limit = (tight == 1 ? s[i]-'0': 9);
        long long ans = 0;
        for(int j = 0; j<=limit; j++){
            int nt = (tight && (j == limit));
            if(!started){
                if(j == 0){
                    ans += dfs(i+1,-1,nt,0);
                } else {
                    ans += dfs(i+1,j,nt,1);
                }
            } else {
                if(abs(j-prev) <= k){
                    ans += dfs(i+1,j,nt,1);
                }
            }
        }
        return dp[i][prev+1][tight][started] = ans;
    }
   long long solve(long long x){
       if(x<0) return 0;
       s = to_string(x);
       dp.assign(18,vector<vector<vector<long long>>>(11,vector<vector<long long>>(2,vector<long long>(2,-1))));
       return dfs(0,-1,1,0);
   }
    long long goodIntegers(long long l, long long r, int K) {
        k = K;
        return solve(r) - solve(l-1);
    }
};