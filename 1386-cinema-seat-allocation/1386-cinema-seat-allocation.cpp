class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Store reserved seats for each row as a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        long long ans = 2LL * (n - mp.size());

        // Process only rows having reserved seats
        for (auto &[row, mask] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Seats 2,3,4,5
            for (int col = 2; col <= 5; col++) {
                if (mask & (1 << col)) {
                    left = false;
                    break;
                }
            }

            // Seats 4,5,6,7
            for (int col = 4; col <= 7; col++) {
                if (mask & (1 << col)) {
                    middle = false;
                    break;
                }
            }

            // Seats 6,7,8,9
            for (int col = 6; col <= 9; col++) {
                if (mask & (1 << col)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                // We can fit two families
                ans += 2;
            }
            else if (left || middle || right) {
                // At least one block is available
                ans += 1;
            }
        }

        return ans;
    }
};