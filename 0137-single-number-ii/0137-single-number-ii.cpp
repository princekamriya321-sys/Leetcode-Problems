class Solution {
public:
bool checkbit(int n,int i){
    int x = 1<<i;
    if((n&x) == 0) return false;
    return true;
}
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0; i<32; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(checkbit(nums[j],i)){
                    count++;
                }
            }
            if(count%3 != 0){
                ans += (1<<i);
            }
        }
        return ans;
    }
};