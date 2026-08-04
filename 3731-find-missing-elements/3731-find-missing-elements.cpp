class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int minele = INT_MAX;
        int maxele = INT_MIN;
        unordered_set<int> st;
        for(int i =0; i<n; i++){
            minele = min(nums[i],minele);
            maxele = max(nums[i],maxele);
            st.insert(nums[i]);
        }
        vector<int> ans;
        for(int i = minele; i<=maxele; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};