class Solution {
public:
  static bool myFunction(string &a,string &b){
     return a.size() < b.size(); 
  }
  bool isPrec(string &a,string &b){
      int n = a.size();
      int m = b.size();
      if(n-m != 1) return false;
     int i =0;
     int j =0;
     while(i<n){
         if(j<m && a[i] == b[j]){
             i++;
             j++;
         } else {
             i++;
         }
     }
      return j == m;
  }
    
    int longestStrChain(vector<string>& words) {
         int n = words.size();
        sort(words.begin(),words.end(),myFunction);
       vector<int>dp(n,1);
       int len = 1;
       for(int i =0; i<n; i++){
           for(int j = 0; j<i; j++){
               if(isPrec(words[i],words[j])){
                   dp[i] = max(dp[i],dp[j]+1);
                   len = max(len,dp[i]);
               }
           }
       }
       return len;
    }
};