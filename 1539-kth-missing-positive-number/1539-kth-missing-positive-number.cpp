class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
           int n = arr.size();
     int lo = 0;
     int hi = n-1;
     while(lo<=hi){
         int m = lo + (hi-lo)/2;
         if(arr[m] - (m+1) < k){
             lo = m+1;
         } else {
             hi = m-1;
         }
     }
     return lo + k;
    }
};