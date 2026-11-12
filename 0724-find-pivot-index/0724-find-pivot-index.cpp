class Solution {
public:
int n;
vector<int> func(vector<int>& nums){
vector<int> prefixsum(n);
prefixsum[0] = nums[0];
for(int i = 1; i<n; i++){
    prefixsum[i] = prefixsum[i-1] + nums[i];
}
return prefixsum;
}
    int pivotIndex(vector<int>& nums) {
        n = nums.size();
        vector<int> prefixsum = func(nums);
        if(prefixsum[n-1]-prefixsum[0] == 0) return 0;
        for(int i =1; i<n-1; i++){
            int leftsum = prefixsum[i-1];
            int rightsum = prefixsum[n-1] - prefixsum[i];
            if(leftsum == rightsum) return i;
        }
        if(prefixsum[n-2] == 0) return n-1;
        return -1;
    }
};