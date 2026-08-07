class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        int idx = 0;
        for(int i = n-2; i>=0; i--){
            if(nums[i+1] > nums[i]){
                pivot = nums[i];
                idx = i;
                break;
            }
        }
        int idx2 = 0;
        int minele = INT_MAX;
        for(int i = idx; i<n; i++){
            if(pivot == -1) break;
            if(nums[i] > pivot && minele > nums[i]){
                minele = nums[i];
                idx2 = i;
            }
        }
        if(pivot == -1){
            sort(nums.begin(),nums.end());
        } else {
     swap(nums[idx],nums[idx2]);
     sort(nums.begin() + idx+1, nums.end());
        }
    }
};