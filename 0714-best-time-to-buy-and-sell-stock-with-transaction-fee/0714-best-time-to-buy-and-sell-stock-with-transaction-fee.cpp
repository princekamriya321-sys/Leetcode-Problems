class Solution {
public:
int n;
vector<vector<int>> dp;
int solve(vector<int>& prices,int i,int buy,int fee){
    if(i >= n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    if(buy){
    int take = solve(prices,i+1,0,fee) - prices[i];
    int not_take = solve(prices,i+1,buy,fee);
    return dp[i][buy] = max(take,not_take);
    } else {
        int take = solve(prices,i+1,1,fee) + prices[i] - fee;
        int not_take = solve(prices,i+1,buy,fee);
        return dp[i][buy] = max(take,not_take);
    }
}
    int maxProfit(vector<int>& prices, int fee) {
           n = prices.size();
     dp.assign(n+1,vector<int>(2,-1));
     return solve(prices,0,1,fee);
    }
};