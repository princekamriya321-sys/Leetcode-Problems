class Solution {
public:
int mod = 1e9+7;
bool checkbit(int n,int i){
    int x = 1<<i;
    if((n&x) != 0) return true;
    return false;
}
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);
        int n = nums.size();
        for(auto& num: nums){
            for(int b = 0; b<32; b++){
                if(checkbit(num,b) == true){
                    count[b]++;
                }
            }
        }
        int ans = 0; 
        while(k--){
        int curr = 0;
        for(int b = 0; b<32; b++){
            if(count[b] > 0){
                count[b]--;
                curr = (curr | (1<<b));
            }
        }
        ans = (ans + 1LL*curr*curr)%mod;
        }
        return ans;
    }
};