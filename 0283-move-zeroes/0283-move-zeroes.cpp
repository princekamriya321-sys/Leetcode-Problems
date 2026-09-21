class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        for(int v: nums){
            if(v == 0) ct++;
        }
        for(int i =0; i<n; i++){
            int j = i;
            while(j<n && nums[j] == 0){
                j++;
            }
            if(nums[i] == 0 && j<n){
            nums[i] = nums[j];
            nums[j] = 0;
            }
        }
        int i = n-1;
        while(ct!= 0){
            nums[i] = 0;
            i--;
            ct--;
        }
    }
};