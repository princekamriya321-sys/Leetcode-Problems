class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        sort(s.begin(), s.end());
        if(s > target)
            return s;

        int n = s.size();

        for(int i = n - 1; i >= 0; i--) {

            string prefix = target.substr(0, i);

            multiset<char> st(s.begin(), s.end());

            bool possible = true;

            for(char c : prefix) {
                auto it = st.find(c);

                if(it == st.end()) {
                    possible = false;
                    break;
                }

                st.erase(it);
            }

            if(!possible)
                continue;

            auto it = st.upper_bound(target[i]);

            if(it == st.end())
                continue;

            string ans = prefix;

            ans += *it;
            st.erase(it);

            for(char c : st)
                ans += c;

            return ans;
        }

        return "";
    }
};