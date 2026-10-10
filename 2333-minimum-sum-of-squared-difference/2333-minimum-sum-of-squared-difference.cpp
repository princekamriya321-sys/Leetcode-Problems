class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long ans = 0;
        vector<int> countdiff(1e5+1,0);
        for(int i =0; i<n; i++){
         int x = abs(nums1[i]-nums2[i]);
         countdiff[x]++;
        }
      int k = k1+k2;
      for(int i = 1e5; i>0 && k > 0; i--){
        int countops = min(countdiff[i],k);
            countdiff[i] -= countops;
            countdiff[i-1] += countops;
           k -= countops;
      }
      long long sum = 0;
     long long i =1;
      while(i<= 1e5){
        sum += 1LL*countdiff[i]*(i*i);
        i++;
      }
      return sum;
    }
};