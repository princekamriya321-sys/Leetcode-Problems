class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long ans = 0;
        bool a = false;
        unordered_set<int> st;
        while(j<n){
            while(i<n && st.find(nums[j]) != st.end()){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        sum += nums[j];
        if(j-i+1 == k){
            a = true;
            ans = max(ans,sum);
            st.erase(nums[i]); 
            sum -= nums[i];
            i++;
        }
        st.insert(nums[j]);
        j++;
        }
        if(a == false) return 0;
        return ans;
    }
};