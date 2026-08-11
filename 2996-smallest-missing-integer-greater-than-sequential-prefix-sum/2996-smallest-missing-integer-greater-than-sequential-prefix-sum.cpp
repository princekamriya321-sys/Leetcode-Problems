class Solution {
public:
    int missingInteger(vector<int>& nums) {
      int n = nums.size();
      unordered_set<int> mp;
      for(int i=0; i<n; i++){
    mp.insert(nums[i]);
      }
        int sum = nums[0];
        for(int j = 1; j<n; j++){
        if(nums[j] == nums[j-1] + 1){
           sum += nums[j];
        } else {
            break;
        }
      }
      while(true){
if(mp.find(sum) == mp.end()) return sum;
sum++;
      }
      return nums[0];
    }
};