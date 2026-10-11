class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n =nums.size();
        vector<int> arr;
        for(int i =0; i<n; i++){
            if(n%(i+1) == 0){
                arr.push_back(nums[i]);
            }
        }
        int ans = 0;
        for(int v: arr){
            ans += v*v;
        }
        return ans;
    }
};