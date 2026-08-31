class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n ==1) return 1;
       int ans = 0;
       int ct = 1;
       int write = 0;
       for(int i =0; i<n-1; i++){
        if(chars[i] != chars[i+1]){
            chars[write++] = chars[i];
            if(ct > 1){
                string count = to_string(ct);
                for(char c: count){
                    chars[write++] = c;
                }
            }
            ct = 1;
        } else {
            ct++;
        }
       }
       chars[write++] = chars[n - 1];
       if(ct > 1){
        string count = to_string(ct);
                for(char c: count){
                    chars[write++] = c;
                }
       }
       return write;
    }
};