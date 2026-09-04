class Solution {
public:
vector<int> maxarray(vector<int>&nums,int n){
    vector<int> maxarr(n);
    maxarr[0] = nums[0];
    for(int i =1; i<n; i++){
        maxarr[i] = max(maxarr[i-1],nums[i]);
    } 
    return maxarr;
}
vector<int> minarray(vector<int>&nums,int n){
    vector<int> minarr(n);
    minarr[n-1] = nums[n-1];
    for(int i =n-2; i>=0; i--){
        minarr[i] = min(minarr[i+1],nums[i]);
    } 
    return minarr;
}
    int firstStableIndex(vector<int>& nums, int k) {
       int n = nums.size(); 
       vector<int> maxarr = maxarray(nums,n);
       vector<int> minarr = minarray(nums,n);
       for(int i = 0; i<n; i++){
        int ans = maxarr[i] - minarr[i];
        if(ans <= k) return i;
       }
       return -1;
    }
};