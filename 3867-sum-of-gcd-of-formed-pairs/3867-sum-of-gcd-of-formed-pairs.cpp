class Solution {
public:
int gcd(int a,int b){
    if(a == 0) return b;
    return gcd(b%a,a);
}
vector<int> func(vector<int>&nums){
    int n = nums.size();
    vector<int>prefixmax(n);
    prefixmax[0] = nums[0];
    for(int i = 1; i<n; i++){
        prefixmax[i] = max(nums[i],prefixmax[i-1]);
    }
    return prefixmax;
}
vector<int> func2(vector<int>&nums,vector<int>& prefixmax){
    int n = nums.size();
    vector<int> prefixgcd(n);
    for(int i = 0; i<n; i++){
        prefixgcd[i] = gcd(nums[i],prefixmax[i]);
    }
    return prefixgcd;
}
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
       vector<int> prefixmax = func(nums);
       vector<int> prefixgcd = func2(nums,prefixmax);
       sort(prefixgcd.begin(),prefixgcd.end());
       vector<int> ans;
       if(n%2 == 0){
        int s = 0;
        int e = n-1;
     
        while(s<e){
            ans.push_back(gcd(prefixgcd[s],prefixgcd[e]));
            s++;
            e--;
            
        }
        long long sum = 0;
        for(int i =0; i<ans.size(); i++){
            sum += ans[i];
        }
        return sum;
       } else {
         int s = 0;
        int e = n-1;
     
        while(s<e){
            ans.push_back(gcd(prefixgcd[s],prefixgcd[e]));
            s++;
            e--;
            
        } 
        long long sum = 0;
        for(int i =0; i<ans.size(); i++){
            sum += ans[i];
        }
        return sum;
       }
    }
};