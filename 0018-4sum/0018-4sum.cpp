class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>>ans;
      for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1])continue;
             int a = nums[i];
        for(int j =i+1; j<n; j++){
            if(j > i+1 && nums[j] == nums[j-1])
    continue;
            int b = nums[j];
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = 1LL*a + b + nums[k] + nums[l];
                if(sum > target){
                l--;
                } else if(sum < target){
                    k++;
                } else {
                    ans.push_back({a,b,nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                }
            }
        }
      }
      return ans;
    }
};