class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxele =0;
        int idx = -1;
        for(int i =0; i<n; i++){
          if(nums[i] > maxele){
            maxele = nums[i];
            idx = i;
          }
        }
        for(int v: nums){
            if(v == maxele) continue;
            if(2*v <= maxele) continue;
            return -1;
        }
        return idx;
    }
};