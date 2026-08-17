class Solution {
public:
vector<vector<int>>dp;
vector<int> prefixsum;
void func(vector<int> &stoneValue){
    int n = stoneValue.size();
    int sum = 0;
    for(int i=0; i<n; i++){
sum += stoneValue[i];
prefixsum[i] = sum;
    }
}
int solve(vector<int>&stoneValue,int l,int r){
    if(l >=r) return 0;
    if(dp[l][r] != -1)return dp[l][r];
    int score = 0;
    for(int mid = l; mid<=r-1; mid++){
        int leftsum = 0;
        int rightsum = prefixsum[r]-prefixsum[mid];
        if(l == 0){
       leftsum = prefixsum[mid];
        } else {
            leftsum = prefixsum[mid] - prefixsum[l-1];
        }
        if(leftsum < rightsum){
            score = max(score,leftsum + solve(stoneValue,l,mid));
        } else if(leftsum > rightsum){
            score = max(score,rightsum + solve(stoneValue,mid+1,r));
        } else {
            score = max({score,leftsum + solve(stoneValue,l,mid),rightsum + solve(stoneValue,mid+1,r)});
        }
    }
    return dp[l][r] = score;
}
    int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    dp.assign(n+1,vector<int>(n+1,-1));
    prefixsum.assign(n,0);
    func(stoneValue);
    return solve(stoneValue,0,n-1);
    }
};