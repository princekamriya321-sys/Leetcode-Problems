class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
       int currsum = 0;
       int bestmin = INT_MAX;
       vector<int> minlentillidx(n,INT_MAX);
       int i = 0;
       int j = 0;
       int result = INT_MAX;
       while(j<n){
        currsum += arr[j];
        while(i<n && currsum > target){
            currsum -= arr[i];
            i++;
        }
        if(currsum == target){
            int len = j-i+1;
        if(i>0 && minlentillidx[i-1] != INT_MAX){
           result = min(result,len + minlentillidx[i-1]);
        }
        bestmin = min(bestmin,len);
        }
        minlentillidx[j] = bestmin;
        j++;
       }
       if(result == INT_MAX) return -1;
       return result;
    }
};