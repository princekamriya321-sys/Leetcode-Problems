class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
    vector<int> prefixsum(n+1);  
    int sum = 0;
    prefixsum[0] = 0;
    for(int i = 0; i<n; i++){
sum += gain[i];
prefixsum[i+1] = sum;
    }
    int mx = INT_MIN;
    for(int i =0; i<prefixsum.size(); i++){
        mx = max(mx,prefixsum[i]);
    } 
    return mx; 
    }
};