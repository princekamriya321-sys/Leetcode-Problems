class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 0;
        int min_price = INT_MAX;

        for (int i = 0; i < n; i++) {
            max_factor = max(max_factor, items[i][0]);
            min_price = min(min_price, items[i][1]);
        }

        vector<int> freq(max_factor + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
        }

        vector<int> mult_cnt(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= max_factor; m += f) {
                mult_cnt[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int val = mult_cnt[items[i][0]];
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + val);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / min_price);
        }

        return ans;
    }
};