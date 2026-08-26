class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i =0; 
        int j = 0;
        int one = 0;
        int st = 0;
        int len = INT_MAX;
        while(j<n){
            if(s[j] == '1') one++;
          while(i<n && one >= k){
         if(len > (j-i + 1) && one == k || (len == (j-i+1) && (s.substr(st,len) > s.substr(i,j-i+1)) && one == k)){
            st = i;
            len = j-i+1;
          }
            if(s[i] == '1') one--;
            i++;
          }
          j++;
        }
        while(i<n && one >= k){
if(len > (j-i + 1) && one == k || (len == (j-i+1 && (s.substr(st,len) > s.substr(i,j-i+1))) && one == k) ){
            st = i;
          len = j-i+1;
          }
            if(s[i] == '1') one--;
            i++;
        }
    string ans = s.substr(st,len);
    if(ans == s){
        int ct = count(s.begin(),s.end(),'1');
        if(ct == k) return s;
        return "";
    }
    return ans;
    }
};