class Solution {
public:
    bool isAnagram(string s, string t) {
      int n = t.size();
      unordered_map<char,int> mp;
      for(int i =0; i<n; i++){
        mp[t[i]]++;
      }  
      int m = s.size();
      if(n != m) return false;
      for(int i =0; i<m; i++){
        if(mp.find(s[i]) == mp.end()){
            return false;
        }
        mp[s[i]]--;
        if(mp[s[i]] == 0){
            mp.erase(s[i]);
        }
      }
      return true;
    }
};