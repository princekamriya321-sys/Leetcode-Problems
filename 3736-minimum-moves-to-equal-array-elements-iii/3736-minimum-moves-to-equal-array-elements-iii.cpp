class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int num = nums[n-1];
        int ct = 0;
        for(int v: nums){
            ct += abs(num-v);
        }
        return ct;
    }
};