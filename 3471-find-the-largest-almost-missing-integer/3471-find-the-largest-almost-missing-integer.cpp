class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
       if(k == 1){
        map<int,int> mp;
        for(int v: nums){
            mp[v]++;
        }
        int ans = -1;
        for(auto it: mp){
            if(it.second == 1 && it.first > ans){
                ans = it.first;
            }
        }
        return ans;
       } else if(k == n){
        int ans = 0;
        for(int v: nums){
            ans = max(v,ans);
        }
        return ans;
       } else {
        int first = nums[0];
        int second = nums[n-1];
        int freq1 = 1;
        int freq2 = 1;
        for(int i =1; i<n-1; i++){
         if(first == nums[i]){
            freq1++;
         }
         if(second == nums[i]){
            freq2++;
         }
        }
        if(first > second){
            if(freq1 == 1) {
                return first;
            } else if(freq2 == 1){
                return second;
            } else {
                return -1;
            }
        } else if(second> first){
            if(freq2 == 1) {
                return second;
            } else if(freq1 == 1){
                return first;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
       }
    }
};