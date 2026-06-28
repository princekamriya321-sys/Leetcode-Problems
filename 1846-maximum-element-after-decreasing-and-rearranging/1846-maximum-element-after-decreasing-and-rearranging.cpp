class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
          int one = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(arr[0] == 1) one++;
        if(one == 0){
            arr[0] = 1;
        }
   for(int i = 1; i<n; i++){
    if(arr[i] - arr[i-1] > 1){
    arr[i] = arr[i-1] + 1;
    }
   }
   int maxele = 0;
   for(int v: arr){
    maxele = max(v,maxele);
   }
   return maxele;
    }
};