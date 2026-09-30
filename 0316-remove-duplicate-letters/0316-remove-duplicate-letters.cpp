class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastused(26);
        vector<bool> taken(26,false);
        stack<char> st;
        for(int i =0; i<n; i++){
            lastused[s[i]-'a'] = i;
        }
        for(int i =0; i<n; i++){
            if(taken[s[i]-'a'] == true) continue;
        while(st.size() > 0 && st.top() > s[i] && lastused[st.top()-'a'] > i){
            taken[st.top()-'a'] = false;
            st.pop();
        }
        if(taken[s[i]-'a'] == false){
        st.push(s[i]);
        taken[s[i]-'a'] = true;
        }
        }
        string result = "";
        while(st.size() > 0){
          result += st.top();
          st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};