class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        int n = knowledge.size();
        for(int i = 0; i<n; i++){
            string k = knowledge[i][0];
            string val = knowledge[i][1];
            mp[k] = val;
         }
         int m = s.size();
         string ans = "";
         for(int i =0; i<m; i++){
            if(s[i] == '('){
                string t = "";
                int j = i+1;
                while(j<m && s[j] != ')'){
                    t += s[j];
                    j++;
                }
                if(mp.find(t) != mp.end()){
                 ans += mp[t];
                } else {
                    ans += '?';
                }
                i = j;
            } else {
                ans+= s[i];
            }
         }
         return ans;
    }
};