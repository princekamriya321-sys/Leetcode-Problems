class Solution {
public:
typedef long long ll;
int N,M;
int dp[2001][2001][2];
int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        ll result = 0;
        // Base case
        for(int startval = 1; startval<=M; startval++){
            dp[N][startval][0] = 1;
            dp[N][startval][1] = 1;
         }
         for(int i = N-1; i>=0; i--){
         vector<ll > cumsum1(M+1,0);
         vector<ll > cumsum0(M+1,0);
         for(int val = 1; val<=M; val++){
            cumsum1[val] = (cumsum1[val-1] + dp[i+1][val][1])%MOD;
            cumsum0[val] = (cumsum0[val-1] + dp[i+1][val][0])%MOD;
         }
         for(int prevval = 1; prevval<=M; prevval++){
            dp[i][prevval][1] = (cumsum0[M] - cumsum0[prevval] + MOD)%MOD;
            dp[i][prevval][0] = cumsum1[prevval-1];
         }
         }
         for(int startval = 1; startval<=M; startval++){
            result = (result + dp[1][startval][1])%MOD;
            result = (result + dp[1][startval][0])%MOD;
         }
        return result;
    }
};