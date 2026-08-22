class Solution {
public:
    bool checkDivisibility(int n) {
        int prd = 1;
        int digitsum = 0;
        int N = n;
        while(n>0){
            int digit = n%10;
            digitsum += digit;
            prd *= digit;
            n /=10;
        }
        int sum = prd + digitsum;
        if(N%sum == 0) return true;
        return false;
    }
};