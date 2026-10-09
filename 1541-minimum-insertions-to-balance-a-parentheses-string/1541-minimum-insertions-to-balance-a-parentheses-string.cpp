class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int ct = 0;
        for(int i =0; i<n; i++){
            if(s[i] == '('){
                open++;
            } else {
                if(open <= 0){
                    if(i+1 <n && s[i+1] == ')'){
                        ct++;
                        i++;
                    } else {
                        ct += 2;
                    }
                } else {
                    if(i+1<n && s[i+1] == ')'){
                        i++;
                    } else {
                        ct++;
                    }
                     open--;
                }
            }
        }
        ct+= 2*open;
        return ct;
    }
};