class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(),t.end());
        if(s == t) return 0;
        if(n == 2) return -1;
        if(s[0] == t[0] || s[n-1] == t[n-1]) return 1;
        char mn = t[0];
        char mx = t[n - 1];
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};