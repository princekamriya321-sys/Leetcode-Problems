class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int mid = 0;
        int hi = n-1;
        while(mid<=hi){
            if(nums[mid] ==0){
         nums[mid] = nums[lo];
         nums[lo] = 0;
         lo++;
         mid++;
            } else if(nums[mid] == 1){
            mid++;
            } else {
         nums[mid] = nums[hi];
         nums[hi] = 2;
         hi--;
            }
        }
    }
};