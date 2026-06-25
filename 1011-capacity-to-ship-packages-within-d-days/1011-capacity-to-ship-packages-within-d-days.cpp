class Solution {
public:
int func(vector<int>&weights,int m){
    int days = 1;
    int n = weights.size();
    int sum = 0;
    for(auto& w: weights){
        if(sum + w > m){
            days++;
            sum = w;
        } else {
            sum += w;
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
         int n = weights.size();
        int lo = 0;
        int hi = 0;
        for(int i = 0; i<n; i++){
            lo = max(lo,weights[i]);
            hi += weights[i];
        }
        int ans = 0;
        while(lo<=hi){
            int m = lo + (hi-lo)/2;
            int reqdays = func(weights,m);
            if(reqdays <= days){
                ans = m;
                hi = m-1;
        } else {
            lo = m+1;
        }
        }
        return ans;
    }
};