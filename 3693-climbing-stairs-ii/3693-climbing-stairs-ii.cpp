class Solution {
public:

    int climbStairs(int n, vector<int>& costs) {
       vector<int> dp(n+1,0);
        for(int i = n-1; i>=0; i--){
            int j = i+1;
            int cost = costs[j-1] + (1) + dp[j];
            j = i+2;
            if(j<=n)
            cost =min(cost,costs[j-1] + 4 + dp[j]);
            j = i+3;
             if(j<=n)
            cost = min(cost,costs[j-1] + 9 + dp[j]);
            dp[i] = cost;
        }
        return dp[0];
    }
};