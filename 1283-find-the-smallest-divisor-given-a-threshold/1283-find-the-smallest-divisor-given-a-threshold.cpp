class Solution {
public:
int sumdivisor(vector<int> &nums,int n,int m){
    long long sum = 0;
    for(int i = 0; i<n; i++){
        sum += ceil((double)nums[i]/m);
    }
    return (int)sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
         int lo = 1;
     int hi = 0;
     int n = nums.size();
     for(int i = 0; i<n; i++){
         hi = max(hi,nums[i]);
     }
     int ans = -1;
        while(lo<=hi){
            int m = lo + (hi-lo)/2;
            if(sumdivisor(nums,n,m) <= threshold){
                ans = m;
                hi = m - 1;
            } else{
                lo = m+1;
            }
        }
        return ans;
    }
};