class Solution {
public:
    bool hasAlternatingBits(int n) {
       int bit = n&1;
       n>>=1;
       while(n>0){
        int alt_bit = (n&1);
        if(alt_bit == bit){
            return false;
        } else {
            bit = alt_bit;
        }
       n>>=1;
       }
       
       return true;
    }
};