class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(vector<int>& piles, int i, int M) {

        if (i >= n)
            return 0;

        // Can take all remaining piles
        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;
        int taken = 0;

        for (int X = 1; X <= 2 * M; X++) {

            taken += piles[i + X - 1];

            // Total stones remaining after I take X
            int remaining = suffix[i + X];

            // Opponent can get solve(...)
            int opponent = solve(piles, i + X, max(M, X));

            // From remaining stones, opponent gets `opponent`,
            // so I get remaining - opponent.
            int myFuture = remaining - opponent;

            ans = max(ans, taken + myFuture);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(piles, 0, 1);
    }
};