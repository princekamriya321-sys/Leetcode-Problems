class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int>& candidates,vector<int>& arr,int target,int i){
      if(target == 0){
        ans.push_back(arr);
        return;
    }
  for(int j = i; j<candidates.size(); j++){
    if(j > i && candidates[j] == candidates[j-1]) continue;
    if(candidates[j] > target) break;
    arr.push_back(candidates[j]);
    solve(candidates,arr,target-candidates[j],j+1);
    arr.pop_back();
  }
    // solve(candidates,arr,target,i+1);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,arr,target,0);
        return ans;
    }
};