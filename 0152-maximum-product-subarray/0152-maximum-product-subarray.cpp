class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
 long long maxprd = INT_MIN;
long long prefix = 1;
long long suffix = 1;
int zero = 0;
for(int x: nums){
    if(x == 0){
        prefix = 1;
        zero++;
    } else {
    prefix *= x;
    maxprd = max(maxprd,prefix);
    } 
}
for(int i = n-1; i>=0; i--){
    int x = nums[i];
    if(x == 0){
        suffix = 1;
    } else {
    suffix *= x;
    maxprd = max(maxprd,suffix);
    } 
}
if(maxprd<0 && zero >0){
    return 0;
}
 return (int)maxprd;
    }
};