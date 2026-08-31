class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
       if(t.size() > s.size()) return "";
       for(char c: t){
        mp[c]++;
       } 
       int i = 0;
       int st = 0;
       int count = t.size();
       int j= 0;
       int len = INT_MAX;
       int n = s.size();
       while(j<n){
        char ch = s[j];
        if(mp[ch] > 0){
            count--;
        }
          mp[ch]--;
        while(count == 0){
            int currlen = j-i+1;
            if(len > currlen){
             len = currlen;
             st = i;
            }
            mp[s[i]]++;
        if(mp[s[i]] > 0){
            count++;
        }
        i++;
        }
        j++;
       }
       if(len == INT_MAX) return "";
       return s.substr(st,len);
    }
};