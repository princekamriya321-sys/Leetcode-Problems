class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    vector<int> comp(n);
        vector<bool> ans;
        comp[0] = 0;
        for(int i =1; i<n; i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                comp[i] = comp[i-1];
            } else {
                comp[i] = comp[i-1] + 1;
            }
        }
        for(int i =0; i<queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];
            ans.push_back(comp[x] == comp[y]);

        }
        return ans;
    }
};