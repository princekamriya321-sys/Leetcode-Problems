class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        int ans = 0;
       for(int i =0; i<n; i++){
        bool found = true;
        for(int j =0; j<m; j++){
            int diff = abs(arr1[i] - arr2[j]);
            if(diff <= d){
                found = false;
                break;
            }
        }
        if(found) ans++;
       }
        return ans;
    }
};