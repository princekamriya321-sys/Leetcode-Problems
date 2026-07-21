class Solution {
public:
vector<vector<int>>dp;
bool solve(string& s,int i ,int j){
    if(i >= j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]){
        return dp[i][j] = solve(s,i+1,j-1);
    }
    return 0;
}
    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        int maxlen = 0;
        int sp = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(solve(s,i,j) == true){
                    if(maxlen< j-i+1){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
return s.substr(sp,maxlen);
    }
};