class Solution {
public:
 vector<int>dp;
    int solve(vector<pair<int,int>>& arr, int i){
        if(i >= arr.size()) return 0;
      if(dp[i] != -1) return dp[i];
        int skip = solve(arr, i + 1);

        int j = i + 1;

       
        if(j < arr.size() && arr[j].first == arr[i].first + 1)
            j++;

        int take = arr[i].second + solve(arr, j);

        return dp[i] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
       int n = nums.size();
       dp.assign(n+1,-1);
        map<int,int> mp;

        for(int x : nums)
            mp[x] += x;          

        vector<pair<int,int>> arr;

        for(auto &it : mp){
            arr.push_back({it.first, it.second});
        }

        return solve(arr,0);
    }
};