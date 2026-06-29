class Solution {
public:
vector<vector<int>> dp;
        int sum = 0;
int helper(vector<int>& arr, int target,int idx){
    if(idx<0){
    if(target == 0) return 1;
    return 0;
    }
    if(abs(target) > sum) return 0;
    if(dp[idx][target+sum] != -1) return dp[idx][target+sum];
    int x = helper(arr,target+arr[idx],idx-1);
     int y = helper(arr,target-arr[idx],idx-1);
    return dp[idx][target+sum] = x+y;
}
    int findTargetSumWays(vector<int>& nums, int target) {
          int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        dp.assign(n+1,vector<int>(2*sum+1,-1));
        int idx = n-1;
        return helper(nums,target,idx);
    }
};