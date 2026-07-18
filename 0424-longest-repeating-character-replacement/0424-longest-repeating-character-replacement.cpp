class Solution {
public:
    int characterReplacement(string s, int k) {
         int n = s.size();
        vector<int> freq(26,0);
        int i =0;
        int j =0;
        int maxfreq = 0;
        int maxlen = 0;
        while(j<n){
            freq[s[j]-'A']++;
            maxfreq = max(maxfreq,freq[s[j]-'A']);
            int len = j-i+1;
            if(len - maxfreq<=k){
                maxlen = max(maxlen,len);
            } else {
                while(i<n && (len-maxfreq > k)){
                freq[s[i]-'A']--;
                i++;
                  maxfreq = 0;
                  for(int k =0; k<25; k++){
                      maxfreq = max(maxfreq,freq[k]);
                  }
                  len = j-i+1;
                }
            }
            j++;
        }
           return maxlen; 
        
        
    }
};