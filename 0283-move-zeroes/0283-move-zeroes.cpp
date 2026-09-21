class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        for(int v: nums){
            if(v == 0) ct++;
        }
    vector<int> ans;
    for(int i =0; i<n; i++){
        if(nums[i] != 0){
            ans.push_back(nums[i]);
        }
    }
    for(int i = 0; i<n;i++){
        nums[i] = 0;
    }
    for(int i =0; i<ans.size(); i++){
        nums[i] = ans[i];
    }
    }
};