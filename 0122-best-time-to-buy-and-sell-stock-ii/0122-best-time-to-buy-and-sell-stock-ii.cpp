class Solution {
public:
vector<vector<int>> dp;
int helper(vector<int>&arr,int buy,int idx){
    if(idx>= arr.size()) return 0;
    if(dp[idx][buy] != -1) return dp[idx][buy];
    if(buy){
        int take = helper(arr,0,idx+1) - arr[idx];
        int not_take = helper(arr,1,idx+1);
        return dp[idx][buy] = max(take,not_take);
    } else {
        int sell = helper(arr,1,idx+1) + arr[idx];
        int not_take = helper(arr,0,idx+1);
        return dp[idx][buy] = max(sell,not_take);
    }
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         dp.assign(n,vector<int>(2,-1));  
      int idx = 0;
      int ans = helper(prices,1,idx);
        return ans;
    }
};