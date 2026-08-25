class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = intervals[0].size();
        if(n == 0) return {};
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>>results;
        results.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            int xo = results.back()[0];
            int yo = results.back()[1];
            if(yo >= x){
               results.back()[1] = max(yo,y);
            } else {
                results.push_back({x,y});
            }
        }
        return results;
    }
};