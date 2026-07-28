class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n%2 == 0){
         string t1 = "";
         for(int i =0; i<n/2; i++){
            t1 += s[i];
         }
         sort(t1.begin(),t1.end());
         string t2 = t1;
         reverse(t2.begin(),t2.end());
         string t = t1 + t2;
         return t;
        } else {
          string t1 = "";
         for(int i =0; i<n/2; i++){
            t1 += s[i];
         }
         sort(t1.begin(),t1.end());
         string t2 = t1;
         t1 += s[n/2];
         reverse(t2.begin(),t2.end());
         string t = t1 + t2;
         return t;
        }
    }
};