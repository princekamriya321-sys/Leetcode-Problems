class Solution {
public:
vector<vector<int>> dp;
int n;
int solve(vector<int>&nums,int i,int x){
    if(i>=n) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int curr_val = nums[i] + x;
    int best = 1;
    int j = lower_bound(nums.begin() + i + 1, nums.end(), curr_val) - nums.begin();
    if(j < n) {
    if (nums[j] == curr_val) {
    best = max(best, 1 + solve(nums, j, 1)); 
     int k = lower_bound(nums.begin() + j + 1, nums.end(), curr_val + 1) - nums.begin();
    if (k < n && nums[k] == curr_val + 1) {
     best = max(best, 1 + solve(nums, k, 0));
    }
    } else if (nums[j] == curr_val + 1) {
     best = max(best, 1 + solve(nums, j, 0));
    }
    }
        return dp[i][x] = best;
}
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
       dp.assign(n, vector<int>(2, -1));
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max({ans, solve(nums, i, 0), solve(nums, i, 1)});
        }
        return ans;
    }
};