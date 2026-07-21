class Solution {
public:
  vector<int >dp;
  int solve(string &digits,int n,int i){
      if(i == n) return 1;
      if(digits[i] == '0') return 0;
      if(dp[i] != -1) return dp[i];
      int x = solve(digits,n,i+1);
      int y = 0;
      if(i+1 < n){
      if(digits[i] == '1' || (digits[i] == '2' && (digits[i+1] <= '6'))){
           y = solve(digits,n,i+2);
      }
      }
      return dp[i] = x+y;
  }
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n+1,-1);
        return solve(s,n,0);
    }
};