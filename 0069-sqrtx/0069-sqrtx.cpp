class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = x;
        int ans =0;
        while(lo<=hi){
            int m = lo + (hi - lo)/2;
            long long sq = 1LL*m*m;
            if(sq == x) return m;
            if(sq > x) {
                hi = m-1;
                ans = hi;
            } else {
                ans = m;
                lo = m+1;
            }
        }
        return ans;
    }
};