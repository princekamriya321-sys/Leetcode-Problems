class Solution {
public:
  vector<vector<int>>dp;
    int ct = 0;
    int solve(vector<int>&arr,int i,int prev){
        if(i == arr.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = 0;
        if(prev == -1 || arr[i] > arr[prev]){
            take = solve(arr,i+1,i) + 1;
        }
        int skip = solve(arr,i+1,prev);
        return dp[i][prev+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,vector<int>(n+1,-1));
                return solve(nums,0,-1);
    }
};