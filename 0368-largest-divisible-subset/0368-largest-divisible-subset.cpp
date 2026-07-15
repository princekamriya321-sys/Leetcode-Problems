class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       vector<int> ans;
       vector<int>dp(n,1);
       vector<int> previdx(n,-1);
       int idx = 0;
       int len = 1;
       for(int i = 0; i<n; i++){
           for(int j =0; j<i; j++){
               if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
                   dp[i] = dp[j]+1;
                   previdx[i] = j;
                   if(len < dp[i]){
                       idx = i;
                       len = dp[i];
                   }
               }
           }
       }
       while(idx != -1){
           ans.push_back(nums[idx]);
           idx = previdx[idx];
       }
       reverse(ans.begin(),ans.end());
       if(n == 1) return nums;
       if(ans.size() == 0){
        return {nums[0]};
       }
       return ans; 
    }
};