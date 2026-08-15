class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
      int ans = 0;
      int zero = 0;
      for(int i=0; i<n; i++){
        ans = ans ^ nums[i];
        if(nums[i] == 0){
            zero++;
        }
      }
      if(zero == n) return 0;
      if(ans != 0){
        return n;
      } else {
        return n-1;
      }
    }
};