class Solution {
public:
vector<vector<vector<int>>> dp;
int helper(vector<int>&arr,int buy,int idx,int cap){
    if(idx>= arr.size() || cap == 0) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    if(buy){
        int take = helper(arr,0,idx+1,cap) - arr[idx];
        int not_take = helper(arr,1,idx+1,cap);
        return dp[idx][buy][cap] = max(take,not_take);
    } else {
        int sell = helper(arr,1,idx+1,cap-1) + arr[idx];
        int not_take = helper(arr,0,idx+1,cap);
        return dp[idx][buy][cap] = max(sell,not_take);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
            dp.assign(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
      int idx = 0;
      int ans = helper(prices,1,idx,k);
        return ans;
    }
};