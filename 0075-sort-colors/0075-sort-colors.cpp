class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        int zero = 0;
        int two =0;
        for(int x: nums){
            if(x == 0){
                zero++;
            } else if(x == 1){
                one++;
            } else {
                two++;
            }
        }
        for(int i =0; i<n; i++){
            if(zero != 0){
                nums[i] = 0;
                zero--;
            } else if(one != 0){
                nums[i] = 1;
                one--;
            } else if(two != 0){
                nums[i] = 2;
                two--;
            }
        }

    }
};