class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n< 3) return n;
        int i =2;
        while(n >= (1<<i)){
            i++;
        }
        return 1<<i;
    }
};