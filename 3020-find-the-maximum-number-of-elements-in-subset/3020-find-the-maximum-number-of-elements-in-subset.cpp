class Solution {
public:
    int maximumLength(vector<int>& nums) {
       map<long long ,int> freq;
       int one = 0;
       for(auto it : nums){
        if(it == 1) one++;
        freq[it]++;
       } 
       if(one != 0 && one %2 == 0){
        one--;
       }
       int ans = one;
       for(auto it : freq){
        long long val = it.first;
        long long base = sqrt(val);
        if((base*base == val) && freq.count(base) && freq[base] > 1){
            continue;
        }
        int count = 0;
        while(freq.count(val) && freq[val] > 1){
            count+= 2;
            val = (val*1LL*val);
        }
        if(freq[val] == 1){
            count++;
        } else {
            count--;
        }
ans = max(ans,count);
       }
       return ans;
    }
};