class Solution {
public:
vector<int> func1(vector<int> &heights){
    int n = heights.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i =0; i<n; i++){
        while(st.size() > 0 && heights[i] < heights[st.top()]){
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }
        st.push(i);
    }
    while(st.size() > 0){
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
    }
    return ans;
}
vector<int> func2(vector<int> &heights){
    int n = heights.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i =n-1; i>=0; i--){
        while(st.size() > 0 && heights[i] < heights[st.top()]){
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }
        st.push(i);
    }
    while(st.size() > 0){
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];
        vector<int> Rse = func1(heights);
        vector<int> Lse = func2(heights);
        int ans = 0;
        for(int i =0; i<n; i++){
            if(i == 0){
                int x = Rse[i];
                int nsr = x-1;
                int len = nsr + 1;
                if(Rse[i] == -1) len = n;
                int ht = heights[i];
                int area = len*ht;
                ans = max(ans,area);
            } else if(i == n-1){
                int nsl = Lse[i] + 1;
                int len = i - nsl + 1;
                if(len > n) len = n;
                int ht = heights[i];
                int area = len*ht;
                ans = max(ans,area);
            } else {
                int nsr = Rse[i] - 1;
                if(nsr < 0) nsr = n-1;
                int nsl = Lse[i] + 1;
                if(nsl == 0) nsl = 0;
                int len = nsr - nsl + 1;
                int ht = heights[i];
                int area = len*ht;
                ans = max(ans,area);
            }
        }
        return ans;
    }
};