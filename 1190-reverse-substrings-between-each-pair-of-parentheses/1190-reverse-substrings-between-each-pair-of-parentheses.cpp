class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
    stack<int> st;
    string t = "";
    for(int i =0; i<n; i++){
     if(s[i] == '('){
        st.push(i);
     } else if(s[i] == ')'){
     reverse(s.begin()+st.top()+1,s.begin()+i);
        st.pop();
     }
    }
        for (char c : s) {
            if (c != '(' && c != ')') {
                t += c;
            }
        }
    return t;
    }
};