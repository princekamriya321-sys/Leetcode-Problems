class Solution {
public:
bool sameFreq(vector<int> freq1,vector<int> freq2){
    for(int i =0; i<26; i++){
        if(freq1[i] != freq2[i]) return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
       vector<int> freq(26,0);
       for(int i =0; i<n; i++){
        freq[s1[i] - 'a']++;
       }
      for(int i =0; i<m; i++){
        int idx = i;
        int windsize = 0;
        vector<int> windfreq(26,0);
        while(windsize < n && idx < m){
            windfreq[s2[idx] - 'a']++;
            windsize++;
            idx++;
        }
        if(sameFreq(freq,windfreq)) return true;
      }
      return false;
    }
};