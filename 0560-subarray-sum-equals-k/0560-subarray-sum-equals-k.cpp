class Solution {
public:
vector<long long> func(vector<int>&nums){
    int n = nums.size();
    vector<long long> prefixsum(n,0);
    long long sum = 0;
    for(int i =0; i<n; i++){
        sum += nums[i];
        prefixsum[i] = sum;
    }
    return prefixsum;
}
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int ans = 0;
      vector<long long> prefixsum = func(nums);
      unordered_map<int,int> mp;
    //    mp[0] = 1;
      for(int i = 0; i<n; i++){
        if(prefixsum[i] == k) ans++;
        int sum = prefixsum[i]-k;
       if(mp.find(sum) != mp.end()){
        ans+=mp[sum];
       }
       mp[prefixsum[i]]++;
      } 
      return ans;
    }
};