class Solution {
public:
    bool isValid(string s) {
                stack<char> st;
int n = s.size();
for(int i =0; i<n; i++){
    if(s[i] == ')' && st.empty()) return false;
     if(s[i] == '}' && st.empty()) return false;
      if(s[i] == ']' && st.empty()) return false;
    if(s[i] == '('){
        st.push(s[i]);
    } else if(s[i] == '{'){
        st.push(s[i]);
    } else if(s[i] == '['){
        st.push(s[i]);
    } else if(!st.empty() && st.top() == '('){
        if(s[i] != ')') return false;
        st.pop();
    } else if(!st.empty() && st.top() == '{'){
        if(s[i] != '}') return false;
        st.pop();
    } else if(!st.empty() && st.top() == '['){
        if(s[i] != ']') return false;
        st.pop();
    }
}
if(st.size() != 0) return false;
else return true;
    }
};