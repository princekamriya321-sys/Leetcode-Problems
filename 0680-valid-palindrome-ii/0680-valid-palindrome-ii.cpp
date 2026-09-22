class Solution {
public:
bool solve(string &s,int i,int j,bool ans){
    if(i>=j) return true;
    if(s[i] != s[j] && ans == false){
        ans = true;
        bool x = solve(s,i+1,j,ans);
        ans = false;
        bool y = solve(s,i,j-1,true);
    return (x||y);
    } else if(s[i] != s[j]){
        return false;
    } 
    return solve(s,i+1,j-1,ans);
}
    bool validPalindrome(string s) {
        int n = s.size();
        bool ans = false;
        return solve(s,0,n-1,ans);
    }
};