class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // position of every original index in sorted order
        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // reach[i] = farthest index reachable from i in one edge
        vector<int> reach(n);

        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && arr[j + 1].first - arr[i].first <= maxDiff)
                j++;
            reach[i] = j;
        }

        const int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = reach[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u, v);

            // Not connected
            if(reach[u] < v && up[LOG-1][u] < v) {
                ans.push_back(-1);
                continue;
            }

            int cur = u;
            int jumps = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    jumps += (1 << k);
                    cur = up[k][cur];
                }
            }

            if(cur < v)
                jumps++;

            ans.push_back(jumps);
        }

        return ans;
    }
};