
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = min(n, 2);

        for (int i = 0; i < n; i++) {
            if (i + 1 >= n || gcd(nums[i], nums[i + 1]) != 1) {
                continue;
            }

            for (int j = i + 2; j < n; j++) {
                bool valid = true;

                for (int p = i; p < j; p++) {
                    if (gcd(nums[p], nums[j]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) {
                    break;
                }

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
