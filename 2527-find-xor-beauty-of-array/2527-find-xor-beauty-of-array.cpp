class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int x : nums){
            ans ^= x;
        }
        return ans;
    }
};