class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
 int maxprd = INT_MIN;
 for(int i =0; i<n; i++){
    int prd = 1;
    for(int j = i; j<n; j++){
prd *= nums[j];
maxprd = max(maxprd,prd);
    }
 }
 return maxprd;
    }
};