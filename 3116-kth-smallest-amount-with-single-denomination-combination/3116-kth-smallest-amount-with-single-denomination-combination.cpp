#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b, long long limit) {
        long long g = gcd(a, b);

        __int128 val = (__int128)(a / g) * b;

        if(val > limit)
            return limit + 1;

        return (long long)val;
    }

    // How many valid amounts are <= x
    long long countValid(long long x, vector<int>& coins, long long k) {

        int n = coins.size();
        long long ans = 0;

        // Inclusion-Exclusion
        for(int mask = 1; mask < (1 << n); mask++) {

            long long currentLCM = 1;
            int bits = 0;
            bool tooLarge = false;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {

                    bits++;

                    currentLCM = lcm(
                        currentLCM,
                        coins[i],
                        x
                    );

                    if(currentLCM > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if(tooLarge)
                continue;

            long long cnt = x / currentLCM;

            if(bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long mn = *min_element(coins.begin(), coins.end());

        // Upper bound:
        // k multiples of the smallest coin
        long long lo = 1;
        long long hi = mn * 1LL * k;

        while(lo < hi) {

            long long mid = lo + (hi - lo) / 2;

            if(countValid(mid, coins, k) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};