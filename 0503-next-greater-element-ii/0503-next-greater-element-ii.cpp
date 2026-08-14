class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
     for(int i =0; i<n; i++){
        while(st.size() > 0 && nums[st.top()] < nums[i]){
            int idx = st.top();
            st.pop();
            ans[idx] = nums[i];
        }
        st.push(i);
     }
     while(st.size() > 0){
        bool found = false;
        for(int i = 0; i<st.top(); i++){
            if(nums[i] > nums[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = nums[i];
                found = true;
                break;
            }
        }
        if(found == true) continue;
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
     }
     return ans;
    }
};