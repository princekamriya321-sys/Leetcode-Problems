class Solution {
public:
    int smallestNumber(int n, int t) {
            string s = to_string(n);
            // if(n%t == 0) return n;
        while(true){
        int prd = 1;
        for(int i =0; i<s.size(); i++){
            prd *= (s[i] - '0');
        }
        if(prd % t == 0) return stoi(s);
        n++; 
        s = to_string(n);
        } 
    }
};