class Solution {
public:

    string makePalindrome(string &left, int mid) {

        string ans = left;

        if(mid != -1)
            ans += char('a' + mid);

        string right = left;
        reverse(right.begin(), right.end());

        ans += right;

        return ans;
    }

    string buildSmallest(string prefix, vector<int> freq, int mid) {

        // Put the smallest available characters
        // after the prefix.
        for(int c = 0; c < 26; c++) {
            while(freq[c] > 0) {
                prefix += char('a' + c);
                freq[c]--;
            }
        }

        return makePalindrome(prefix, mid);
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int h = n / 2;

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        // Find the middle character.
        int mid = -1;
        int odd = 0;

        for(int c = 0; c < 26; c++) {

            if(freq[c] % 2 == 1) {
                odd++;
                mid = c;
            }
        }

        // More than one odd frequency => palindrome impossible.
        if(odd > 1)
            return "";

        // Frequency for left half.
        vector<int> half(26);

        for(int c = 0; c < 26; c++)
            half[c] = freq[c] / 2;

        /*
            First try to make the left half equal to
            target's left half.
        */

        vector<int> remaining = half;

        int matched = 0;

        while(matched < h) {

            int c = target[matched] - 'a';

            if(remaining[c] == 0)
                break;

            remaining[c]--;
            matched++;
        }

        /*
            Case 1:
            We matched the entire left half.

            Example:

                target = abba
                left   = ab

            Build abba and see whether it is strictly greater.
        */

        if(matched == h) {

            string left = target.substr(0, h);

            string candidate = makePalindrome(left, mid);

            if(candidate > target)
                return candidate;
        }

        /*
            Now we need to make the palindrome GREATER.

            There are two possibilities:

            1. The first mismatch happened at 'matched'.
               Try a character > target[matched].

            2. If that doesn't work, go backwards and
               increase an earlier character.
        */

        for(int i = matched; i >= 0; i--) {

            vector<int> cur = half;

            /*
                Keep target[0 ... i-1] exactly the same.
            */

            bool valid = true;

            for(int j = 0; j < i; j++) {

                int c = target[j] - 'a';

                if(cur[c] == 0) {
                    valid = false;
                    break;
                }

                cur[c]--;
            }

            if(!valid)
                continue;

            /*
                At position i, choose the SMALLEST character
                strictly greater than target[i].
            */

            int original = target[i] - 'a';

            for(int c = original + 1; c < 26; c++) {

                if(cur[c] == 0)
                    continue;

                string left = target.substr(0, i);

                left += char('a' + c);

                cur[c]--;

                /*
                    Fill remaining positions with the smallest
                    possible characters.
                */

                for(int x = 0; x < 26; x++) {

                    while(cur[x] > 0) {
                        left += char('a' + x);
                        cur[x]--;
                    }
                }

                return makePalindrome(left, mid);
            }
        }

        return "";
    }
};