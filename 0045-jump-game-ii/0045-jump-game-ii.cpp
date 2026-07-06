class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       int farthest = 0;
       int currend = 0;
       int jump = 0;
       for(int i =0; i<n-1; i++){
        farthest = max(farthest,nums[i]+i);
        if(currend == i){
            jump++;
             currend = farthest;
        }
       } 
       return jump;
    }
};