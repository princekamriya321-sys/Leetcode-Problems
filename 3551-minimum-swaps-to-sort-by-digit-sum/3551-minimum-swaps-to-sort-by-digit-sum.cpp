class Solution {
public:
int getDigitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
auto valid = [this](int num1, int num2) {
    int sum1 = getDigitSum(num1);
    int sum2 = getDigitSum(num2);

    if (sum1 != sum2) return sum1 < sum2;
    return num1 < num2;
};
        for(int v: nums){
           arr.push_back(v);
        }
        sort(arr.begin(),arr.end(),valid);
        unordered_map<int,int> mp;
        for(int i =0; i<n; i++){
            mp[nums[i]] = i; 
        }
        int ct = 0;
        for(int i =0; i<n; i++){
            if (nums[i] != arr[i]) {
                int idx = mp[arr[i]];
                swap(nums[i], nums[idx]);
                mp[nums[idx]] = idx;
                mp[nums[i]] = i;
                ct++;
            }
        }
        return ct;
    }
};