class Solution {
public:
int gcd(int a,int b){
    if(a== 0){
        return b;
    }
    int temp = gcd(b%a,a);
    return temp;
}
    int findGCD(vector<int>& nums) {
        int s = INT_MAX;
        int l = INT_MIN;
        int n = nums.size();
        for(int i =0; i<n; i++){
            s = min(s,nums[i]);
            l = max(l,nums[i]);
        }
        int ans = gcd(s,l);
        return ans;
    }
};