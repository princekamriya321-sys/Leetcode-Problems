class Solution {
public:
   vector<vector<int>>dp;
    int helper(vector<int> &coins,int amount,int idx){
       if(idx == 0){
        if(amount % coins[0] == 0) return amount/coins[0];
        return 1e9;
       }
        if(idx<0) return 1e9;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int x = helper(coins,amount,idx-1);
        int y = INT_MAX;
        if(amount>=coins[idx]){
            y = helper(coins,amount-coins[idx],idx) +1;
        }
        return dp[idx][amount] = min(x,y);
    }
    int coinChange(vector<int>& coins, int amount) {
          int n = coins.size();
        int idx = n-1;
        dp.assign(n+1,vector<int>(amount+1,-1));
        int ans = helper(coins,amount,idx); 
        if(ans >=1e9) return -1;
        return ans;
    }
};