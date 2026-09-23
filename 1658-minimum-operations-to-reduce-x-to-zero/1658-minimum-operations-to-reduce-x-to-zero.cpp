class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i =0;
        int j = 0;
       int total_sum = accumulate(nums.begin(), nums.end(), 0);
       int req = total_sum - x;
       if(req == 0) return n;
        int sum = 0;
        int ct= -1;
      while(j<n){
      sum += nums[j];
      while(i<n && sum > req){
        sum -= nums[i];
        i++;
      }
      if(sum == req){
        ct = max(ct,j-i+1);
      }
      j++;
      }
      if(ct == -1) return -1;
      return n-ct;
    }
};