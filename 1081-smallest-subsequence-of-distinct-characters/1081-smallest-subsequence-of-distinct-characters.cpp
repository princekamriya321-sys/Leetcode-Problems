class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
       stack<char> st;
       vector<int> lastused(26,0);
       vector<bool> taken(26,false);
       for(int i =0; i<n; i++){
        lastused[s[i]-'a'] = i;
       }
       for(int i =0; i<n; i++){
       if(taken[s[i]-'a'])
         continue;
        while(st.size() > 0 && st.top()> s[i] && lastused[st.top()-'a'] > i){
                char ch = st.top();
                st.pop();
                taken[ch-'a'] = false;
            
        }
            st.push(s[i]);
            taken[s[i]-'a'] = true;
       }
       string result = "";
       while(st.size()>0){
        result += st.top();
        st.pop();
       }
       reverse(result.begin(),result.end());
       return result;
    }
};