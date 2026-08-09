class Solution {
public:
bool isPalindrome(string& s,int str,int end){
    if(str >= end) return true;
    if(s[str] != s[end]) return false;
    return isPalindrome(s,str+1,end-1);
}
void solve(string &s,int idx,vector<string> &curr,vector<vector<string>>&result){
    if(idx == s.size()){
        result.push_back(curr);
    }
    for(int i =idx; i<s.size(); i++){
        if(isPalindrome(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,curr,result);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> result;
        vector<string> curr;
        solve(s,0,curr,result);
        return result;
    }
};