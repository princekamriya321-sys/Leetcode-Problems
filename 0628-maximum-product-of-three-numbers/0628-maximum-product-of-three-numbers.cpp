class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int ans1 = nums[n]*nums[n-1]*nums[n-2];
        int ans2 = nums[0]*nums[1]*nums[n];
        if(ans1> ans2){
            return ans1;
        } else {
        return ans2;
        }
    }
};