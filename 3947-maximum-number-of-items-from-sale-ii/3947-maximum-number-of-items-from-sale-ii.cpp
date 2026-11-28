class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int min_price = INT_MAX;

        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
            min_price = min(min_price, items[i][1]);
        }

        vector<int> mult_cnt(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                mult_cnt[f] += freq[m];
            }
        }

        vector<pair<long long, long long>> deals;
        for (int i = 0; i < n; i++) {
            long long bonus = mult_cnt[items[i][0]] - 1;
            long long price = items[i][1];
            if (bonus > 0 && price < 2LL * min_price) {
                deals.push_back({price, bonus});
            }
        }

        sort(deals.begin(), deals.end());

        long long rem = budget;
        long long total = 0;
        long long last_price = -1;

        for (auto& d : deals) {
            long long price = d.first;
            long long cap = d.second;
            if (rem < price) break;
            long long buy = min(cap, rem / price);
            rem -= buy * price;
            total += buy * 2;
            if (buy > 0) last_price = price;
        }

        long long ans = total + rem / min_price;
        if (last_price != -1) {
            ans = max(ans, (total - 2) + (rem + last_price) / min_price);
        }

        return (int)ans;
    }
};