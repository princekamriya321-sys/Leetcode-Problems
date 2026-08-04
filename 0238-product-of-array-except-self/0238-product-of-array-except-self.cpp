class Solution {
public:
 vector<int> func(vector<int>&nums){
    int n = nums.size();
    vector<int> prefixprd(n);
    prefixprd[0] = nums[0];
    for(int i =1; i<n; i++){
        prefixprd[i] = prefixprd[i-1]*nums[i];
    }
    return prefixprd;
 }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixprd = func(nums);
        int suffix = 1;
        for(int i =n-1; i>0; i--){
            prefixprd[i] = prefixprd[i-1]*suffix;
            suffix *= nums[i];
        }
        prefixprd[0] = suffix;
        return prefixprd;
    }
};