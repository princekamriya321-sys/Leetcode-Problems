class Solution {
public:
vector<int> dp;
int solve(vector<int>& stoneValue,int i){
if(i>= stoneValue.size()) return 0;
int ans = INT_MIN;
int n = stoneValue.size();
if(dp[i] != INT_MIN) return dp[i];
int take = 0;
for(int k =0; k<3 && i+k < n; k++){
take += stoneValue[i+k];
ans = max(ans,take - solve(stoneValue,i+k+1));
}
return dp[i] = ans;
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n,INT_MIN);
        if(solve(stoneValue,0) > 0){
            return "Alice";
        } else if(solve(stoneValue,0) < 0){
            return "Bob";
        } else {
            return "Tie";
        }
    }
};