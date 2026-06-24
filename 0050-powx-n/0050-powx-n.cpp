class Solution {
public:
 double pow(double a, long long b){
        if(b == 0){
            return 1;
        }
        double val = pow(a,b/2);
        if(b%2 == 0){
            return val*val;
        } else{
            return val*val*a;
        }
    }
    double myPow(double x, int n) {
          if(n < 0){
            return pow(1/x,n);
        } else {
            return pow(x,n);
        }
    }
};