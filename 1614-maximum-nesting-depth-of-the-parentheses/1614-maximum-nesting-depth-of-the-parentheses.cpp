class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int ct = 0;
        for(int i =0; i<n; i++){
            if(s[i] == '('){
                ct++;
            } else if(s[i] == ')'){
                ans = max(ans,ct);
                ct--;
            }
        }
        return ans;
    }
};