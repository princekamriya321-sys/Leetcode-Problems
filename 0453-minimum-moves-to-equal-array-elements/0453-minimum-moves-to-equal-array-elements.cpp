class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n= nums.size(); 
       int minele = INT_MAX;
       int ans = 0;
       for(int v: nums){
        minele = min(v,minele);
       }
       for(int i=0; i<n; i++){
        ans += nums[i] - minele;
       }
       return ans;
    }
};