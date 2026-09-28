class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int v: nums){
            sum += v;
        }
        if(sum%k == 0) return n;
        for(int i =0; i<n; i++){
         if((sum - 2*nums[i])%k  == 0) return n;
        }
        int ans = 0;
    for(int i =0; i<n; i++){
        unordered_map<int,int> mp;
        sum = 0;
        for(int j = i; j<n; j++){
        sum += nums[j];
        int x = (2LL*nums[j])%k;
        if(x<0) x+= k;
        mp[x]++;
        int rem = ((sum%k) + k)%k;
        if(rem == 0 || mp.count(rem) >=1){
            ans = max(ans,j-i+1);
        }
        }
    }
       return ans;
    }
};