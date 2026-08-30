class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minele = INT_MAX;
        int minidx = 0;
        int maxele = INT_MIN;
        int maxidx = 0;
        for(int i =0; i<n; i++){
         if(nums[i] > maxele){
            maxidx = i;
            maxele = nums[i];
         }
         if(nums[i] < minele){
            minele = nums[i];
            minidx = i;
         }
        }
        int ans1 = min(minidx+1,n-minidx);
        ans1 += min(maxidx+1,n-maxidx);
        int ans2 = min(minidx+1,maxidx+1) + abs(minidx-maxidx);
        int ans3 = min(n-maxidx,n-minidx) + abs(minidx-maxidx);
        return min({ans1,ans2,ans3});
    }
};