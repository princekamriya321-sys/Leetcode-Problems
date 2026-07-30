class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        string s = word;
       
      vector<int> freq(26,0);
     for(int i =0; i<n; i++){
        freq[s[i]-'a']++;
     }
     int ct = 0;
     for(int i =0; i<26; i++){
        if(freq[i] > 0){
            ct++;
        }
     }
     int ans = 0;
        for(int i = 0; i < ct; i++) {
            ans += i / 8 + 1;
        }

        return ans;
    }
};