class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
       bool ans = false;
       for(int i =0; i<n; i++){
        if(nums[i] == target) ans = true;
       }
       if(ans == false) return 0;
       int ct = 0;
       for(int sp = 0; sp<n; sp++){
        int count_target = 0;
        for(int ep = sp; ep<n; ep++){
          if(nums[ep] == target){
            count_target++;
          }
          if(count_target > (ep-sp+1)/2){
            ct++;
          }
        }
       }
       return ct;
    }
};