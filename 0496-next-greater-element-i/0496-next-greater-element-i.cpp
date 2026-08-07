class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<int> ans(n,0);
    stack<int> st;   
    for(int i = 0; i<n; i++){
        while(st.size()>0 && nums2[i]> nums2[st.top()]){
            int idx = st.top();
            ans[idx] = nums2[i];
            st.pop();
        }
        st.push(i);
    }
    while(st.size()>0){
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
    }
int m = nums1.size();
for(int i =0; i<m; i++){
    for(int j = 0; j<n; j++){
        if(nums1[i] == nums2[j]){
            nums1[i] = j;
            break;
        }
    }
}
for(int i =0; i<m; i++){
    nums1[i] = ans[nums1[i]];
}
return nums1;
    }
};