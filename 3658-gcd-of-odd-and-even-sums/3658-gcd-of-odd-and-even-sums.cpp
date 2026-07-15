class Solution {
public:
int gcd(int a,int b){
    if(a== 0) return b;
    return gcd(b%a,a);
}
    int gcdOfOddEvenSums(int n) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i<=2*n; i+=2){
            sum1 += i;
        }
        for(int i = 1; i<=2*n; i+=2){
            sum2 += i;
        }
        return gcd(sum1,sum2);
    }
};