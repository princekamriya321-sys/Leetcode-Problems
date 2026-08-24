class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int>&nums,vector<int>&arr,int i){
    if(i == nums.size()){
        ans.push_back(arr);
        return;
    }
   arr.push_back(nums[i]);
   solve(nums,arr,i+1);
   arr.pop_back();
   int idx = i+1;
   while(idx != nums.size() && nums[i] == nums[idx]){
    idx++;
   }
   solve(nums,arr,idx);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        sort(nums.begin(),nums.end());
    solve(nums,arr,0);
    return ans;
    }
};