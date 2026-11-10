class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxL = 0;
        int idx = 0;
        for(int i =0; i<n; i++){
           dp[i][i] = true;
           maxL = 1;
        }
        for(int l = 2; l<=n; l++){
            for(int i = 0; i<n-l+1; i++){
                int j = l+i-1;
             if(s[i] == s[j] && l == 2){
                dp[i][j] = true;
                maxL = 2;
                idx = i;
             } else if(s[i] == s[j] && dp[i+1][j-1] == true){
                dp[i][j] = true;
                if(j-i+1>maxL){
                    maxL = j-i+1;
                    idx = i;
                }
             } else {
                dp[i][j] = false;
             }
            }
        }
            return s.substr(idx,maxL);
    }
};