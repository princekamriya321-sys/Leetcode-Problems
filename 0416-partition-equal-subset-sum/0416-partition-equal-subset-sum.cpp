class Solution {
public:
vector<vector<int>> dp;
bool helper(int n,vector<int> &nums ,int target,int idx){
        if(target == 0) return 1;
    if(idx < 0) return 0;
    if(dp[idx][target] != -1) return dp[idx][target];
    int x = helper(n,nums,target,idx-1);
    int y = 0;
    if(target >= nums[idx]){
        y = helper(n,nums,target-nums[idx],idx-1);
    }
    if(x == 0 && y == 0){
     dp[idx][target] = 0;
    return false;
    } else {
        dp[idx][target] = 1;
        return true;
    }
}
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        int x = sum/2;
        int idx = n-1;
        dp.assign(n+1,vector<int>(x+1,-1));
        return helper(n,nums,x,idx);  
    }
};