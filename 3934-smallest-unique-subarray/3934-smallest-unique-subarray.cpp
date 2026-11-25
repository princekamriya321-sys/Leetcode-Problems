
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<map<int,int>> next(2 * n + 2);
        vector<int> link(2 * n + 2, -1);
        vector<int> len(2 * n + 2, 0);
        vector<int> cnt(2 * n + 2, 0);

        int sz = 1;
        int last = 0;

        for (int x : nums) {
            int cur = sz++;

            len[cur] = len[last] + 1;
            cnt[cur] = 1;

            int p = last;

            while (p != -1 && !next[p].count(x)) {
                next[p][x] = cur;
                p = link[p];
            }

            if (p == -1) {
                link[cur] = 0;
            } 
            else {
                int q = next[p][x];

                if (len[p] + 1 == len[q]) {
                    link[cur] = q;
                } 
                else {
                    int cl = sz++;

                    len[cl] = len[p] + 1;
                    next[cl] = next[q];
                    link[cl] = link[q];

                    while (p != -1 && next[p][x] == q) {
                        next[p][x] = cl;
                        p = link[p];
                    }

                    link[q] = cl;
                    link[cur] = cl;
                }
            }

            last = cur;
        }

        vector<int> order(sz);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return len[a] > len[b];
        });

        for (int v : order) {
            if (link[v] > 0) {
                cnt[link[v]] += cnt[v];
            }
        }

        int ans = n;

        for (int v = 1; v < sz; v++) {
            if (cnt[v] == 1) {
                ans = min(ans, len[link[v]] + 1);
            }
        }

        return ans;
    }
};
