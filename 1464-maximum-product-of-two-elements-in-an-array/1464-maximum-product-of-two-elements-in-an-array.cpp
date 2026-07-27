class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        int n = nums.size();
        if(n == 2) return (nums[0]-1)*(nums[1]-1);
        int ct = 0;
        for(int i =0; i<n; i++){
            max1 = max(max1,nums[i]);  
        }
        for(int i =0; i<n; i++){
            if(nums[i] == max1) ct++;
        }
        if(ct >= 2){
            return (max1-1)*(max1-1);
        } else {
            for(int i =0; i<n; i++){
                if(nums[i] == max1) continue;
                max2 = max(nums[i],max2);
            }
            return (max1-1)*(max2-1);
        }

    }
};