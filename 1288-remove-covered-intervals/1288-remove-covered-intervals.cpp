class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int n = intervals.size();
        for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        if(i == j) continue;

        if(intervals[j][0] <= intervals[i][0] &&
           intervals[j][1] >= intervals[i][1])
        {
            ans++;
            break;  
        }
    }
}
        return n-ans;
    }
};