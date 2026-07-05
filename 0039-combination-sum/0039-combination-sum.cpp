class Solution {
public:
  vector<vector<int>> ans;
  vector<int > arr;
  void solve(vector<int>& prices,int budget,int n,int i){
      if(budget == 0){
          ans.push_back(arr);
          return;
      }
      if(i == n){
          if(budget == 0){
              ans.push_back(arr);
          }
          return;
      }
      if(budget>= prices[i]){
      arr.push_back(prices[i]);
      solve(prices,budget-prices[i],n,i);
      arr.pop_back();
      }
      solve(prices,budget,n,i+1);
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        solve(candidates,target,n,0);
        return ans;
    }
};