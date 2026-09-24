class Solution {
public:
    int smallestIndex(vector<int>& nums) {
       int n = nums.size();
       for(int i =0; i<n; i++){
        int sum = 0;
        string s = to_string(nums[i]);
        if(nums[i] <= 9){
            if(nums[i] == i) return i;
        } else {
            for(int j = 0; j<s.size(); j++){
                sum += (s[j]-'0');
            }
            if(sum == i) return i;
        }
        
        } 
        return -1;
    }
};