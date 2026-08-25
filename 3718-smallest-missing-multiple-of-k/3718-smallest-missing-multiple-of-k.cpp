class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n =nums.size();
        int ans = k;
        unordered_set<int>st;
        for(int i =0; i<n; i++){
        st.insert(nums[i]);
        }
        int num = k;
       for(int i =1; i<=k*n; i++){
       if(st.find(num) == st.end())return num;
       num = num + k;
       }
       return num;
    }
};