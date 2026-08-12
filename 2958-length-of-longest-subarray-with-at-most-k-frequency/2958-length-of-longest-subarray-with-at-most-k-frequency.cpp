class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long,int> freq;
        int i =0; 
        int j = 0;
        int len = 0;
        while(j < n){
         freq[nums[j]]++;
         while(i<n && freq[nums[j]] > k){
            freq[nums[i]]--;
            i++;
         }
         len = max(len,j-i+1);
         j++;
        }
        return len;
    }
};