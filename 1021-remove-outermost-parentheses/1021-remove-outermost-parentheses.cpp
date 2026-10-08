class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int ct = 0;
        string t = "";
        for(int i =0; i<n; i++){
         if(s[i] == '('){
           if(ct == 0){
           } else {
            t += s[i];
           }
           ct++;
        }
         if(s[i] == ')'){
            ct--;
          if(ct != 0){
            t += s[i];
          }
         }
        }
        return t;
    }
};