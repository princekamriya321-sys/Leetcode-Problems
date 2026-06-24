class Solution {
public:
    string countAndSay(int n) {
        string s;
        s = "1";
        for(int i =2; i<=n; i++){
            int ct = 1;
            string temp = "";
            for(int j = 1; j<=s.size(); j++){
            if(j<s.size() && s[j-1] == s[j]){
                ct++;
            } else {
           temp += to_string(ct);
           temp += s[j-1];
           ct = 1;
            }
            }
              s = temp;
        }
        return s;
    }
};