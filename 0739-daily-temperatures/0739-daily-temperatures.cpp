class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i =0; i<n; i++){
    while(st.size() > 0 && temperatures[i] > temperatures[st.top()]){
        int idx = st.top();
        st.pop();
        ans[idx] = i - idx;
    }
    st.push(i);
    }
    while(st.size() > 0){
        int idx = st.top();
        st.pop();
        ans[idx] = 0;
    }
    return ans;
    }
};