class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int ct1 = 1;
        int ct2 = 1;
         
        int n = nums.size();
        for(int i =1; i<n; i++){
            if(nums[i] > nums[i-1]){
                ct1++;
                ans = max({ans,ct1,ct2});
                ct2 = 1;
            } else if(nums[i] < nums[i-1]){
                ct2++;
                 ans = max({ans,ct1,ct2});
                ct1 = 1;
            } else{
                 ans = max({ans,ct1,ct2});
                ct1 = 1;
                ct2 = 1;
            }
        }
         ans = max({ans,ct1,ct2});
         return ans;
    }
};