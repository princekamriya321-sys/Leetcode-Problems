class Solution {
public:
vector<vector<int>> dp;
int solve(vector<int>&prices,int i,int buy){
    if(i >= prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    if(buy){
        int x = solve(prices,i+1,0) - prices[i];
        int y = solve(prices,i+1,buy);
        return dp[i][buy] = max(x,y);
    } else {
        int x = prices[i];
        int y = solve(prices,i+1,buy);
        return dp[i][buy] = max(x,y);
    }
}
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int buy = prices[0];
        int n = prices.size();
        dp.assign(n+1,vector<int>(2,-1));
        int ans = solve(prices,0,1);
        return ans;
    }
};