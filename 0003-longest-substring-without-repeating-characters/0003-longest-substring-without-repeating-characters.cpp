class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.size();
       int len = 0;
       int i = 0;
          vector<int> freq(256,0);
      for(int j = 0; j<n; j++){
          freq[s[j]]++;
          while(freq[s[j]] > 1){
              freq[s[i]]--;
              i++;
          }
          len = max(len,j-i+1);
      }
        return len;
    }
};