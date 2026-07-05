class Solution {
public:
    int bulbSwitch(int n) {
       long long limit = sqrt(n);
       if((limit+1)*(limit+1) <= n){
        limit++;
       } 
       return limit;
    }
};