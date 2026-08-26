class Solution {
public:
    int numTrees(int n) {
          long long mod = 1e9+7;
        vector<long long> catalan(n+1,0);
       long long i,j;
       catalan[0] = 1;
        for(i = 1; i<=n; i++){
            catalan[i] = 0;
            for(j =0; j<i; j++){
                catalan[i] += (1LL*catalan[j]*catalan[i-1-j]);
                catalan[i] = (catalan[i]);
            }
        }
        if(catalan[n] >=INT_MAX) return INT_MAX;
        return (int)catalan[n]; 
    }
};