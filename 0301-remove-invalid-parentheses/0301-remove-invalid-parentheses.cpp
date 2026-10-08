class Solution {
public:
unordered_set<string> st;
int n;
int maxLen;
void solve(string& s,int i,int ct,string &t){
    if(ct<0) return;
    if(i>= n){
        if(ct == 0){
        if(t.size() > maxLen){
            maxLen = t.size();
            st.clear();
        }
        if(t.size() == maxLen){
            st.insert(t);
        }
        }
        return;
    }
    if(s[i] != '(' && s[i] != ')'){
       t.push_back(s[i]);
            solve(s, i + 1, ct, t);
            t.pop_back();
            return;
    }
    t.push_back(s[i]);
    solve(s,i+1,ct + (s[i] == '(' ? 1: (-1)),t);
    t.pop_back();
    solve(s,i+1,ct,t);
}
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        string t = "";
        maxLen = 0;
        solve(s,0,0,t);
vector<string> ans;
for(auto &sr : st) {
        ans.push_back(sr);
}
        return ans;
    }
};