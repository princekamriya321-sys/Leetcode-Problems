class Solution {
public:
typedef long long ll;
int m = 1337;
int binexp(int a,int b){
    int ans = 1;
    while(b > 0){
        if(b& 1){
            ans = (ans*1LL*a)%m;
        }
        a = (a*1LL*a)%m;
        b >>= 1;
    }
    return ans;
}
    int superPow(int a, vector<int>& b) {
        if(a == 1) return 1;
        ll power = 0;
        int mod = 1140;
        bool nonzero = false;
        int n = b.size();
        int pow10 = 1;
        for(int i =n-1; i>=0; i--){
            if(b[i] == 0) nonzero = true;
        power = (power + pow10*1LL*b[i])%mod;
         pow10 = (pow10*10LL)%mod;
        }
        if(power == 0 && nonzero) power += mod;
return binexp(a,(int)power);
    }
};