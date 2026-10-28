
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][x] = whether XOR value x is possible
        // for a path from (0,0) to (i,j).
        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(m, vector<bool>(1024, false))
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                int val = grid[i][j];

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ val] = true;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ val] = true;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][m - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
