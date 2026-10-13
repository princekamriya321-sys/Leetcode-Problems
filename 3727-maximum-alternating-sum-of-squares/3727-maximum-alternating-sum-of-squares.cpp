class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        vector<int> arr(n);
        int i =0;
        int j =n-1;
        int ct = 0;
        int k =0;
        while(i<= j){
        if(i == j){
            arr[k] = nums[i];
            i++;
            break;
        }
         if(ct%2 == 0){
            arr[k] = nums[j];
            j--;
         } else {
            arr[k] = nums[i];
            i++;
         }
         ct++;
         k++;
        }
        long long sum = 0;
        i = 0;
        while(i<n){
            if(i%2 == 0){
                sum += 1LL*arr[i]*arr[i];
            } else {
                sum -= 1LL*arr[i]*arr[i];
            }
            i++;
        }
        return sum;
    }
};