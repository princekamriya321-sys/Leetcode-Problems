class Solution {
public:
int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ct = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i =0; i<n; i++){
          sum += arr[i];
          if(sum%2 != 0){
            int prev_count = mp[0];
            ct = (ct + prev_count+1)%mod;
          } else {
             int prev_count = mp[1];
            ct = (ct + prev_count)%mod;
          }
          if(sum%2 == 0){
            mp[0] = (mp[0] + 1)%mod;
          } else {
            mp[1] = (mp[1] + 1)%mod;
          }
        }
return ct;
    }
};