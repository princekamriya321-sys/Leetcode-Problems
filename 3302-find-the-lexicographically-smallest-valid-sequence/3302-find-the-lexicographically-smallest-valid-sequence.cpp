class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        if (word2.size() == 1)
            return {0};

        int n = word1.size();
        int m = word2.size();

        // suf[i] = first unmatched position in word2
        // after matching greedily using word1[i...]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j])
                j--;
            suf[i] = j + 1;
        }

        vector<int> ans;

        int p = 0;
        bool used = false;

        for (int i = 0; i < n && ans.size() < m; i++) {

            if (word1[i] == word2[p]) {
                ans.push_back(i);
                p++;
            }
            else if (!used) {
                // Can we spend the one mismatch here?
                if ((m - suf[i + 1]) + p + 1 >= m) {
                    ans.push_back(i);
                    p++;
                    used = true;
                }
            }
        }

        if ((int)ans.size() != m)
            return {};

        return ans;
    }
};