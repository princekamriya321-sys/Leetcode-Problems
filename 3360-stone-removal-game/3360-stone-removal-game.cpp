class Solution {
public:
    bool canAliceWin(int n) {
       int k = 10;
        bool alice = true;

        while (k > 0 && n >= k) {
            n -= k;
            k--;
            alice = !alice;
        }

        return !alice;
    }
};