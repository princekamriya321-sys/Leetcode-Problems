class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int k = p.size();
       int n = s.size();
       vector<int> P_count(26);
       for(char c: p){
        P_count[c-'a']++;
       }
       vector<int> ans;
       for(int i = 0; i<=n-k; i++){
        vector<int> S_count(26,0);
        for(int j = i; j<i+k; j++){
            S_count[s[j]-'a']++;
        }
        if(P_count == S_count){
            ans.push_back(i);
        }
       }
       return ans;
    }
};