class Solution {
public:
vector<vector<int>> ans;
vector<int> arr;
void solve(vector<int>&nums,int n,int i){
    if(i == n){
        ans.push_back(arr);
        return;
    }
arr.push_back(nums[i]);
solve(nums,n,i+1);
arr.pop_back();
solve(nums,n,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,nums.size(),0);
    
       return ans; 
    }
};