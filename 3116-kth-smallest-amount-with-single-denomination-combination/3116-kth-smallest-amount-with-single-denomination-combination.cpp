#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
ll gcd(ll a,ll b){
    if(a== 0) return b;
    return gcd(b%a,a);
}
ll countSmaller(vector<int> &coins,ll mid){
    ll correctedcount = 0;
    int n = coins.size();
    for(int i = 1; i<=(1<<n)-1; i++){
    ll order = 0;
    ll lcm = 0;
    for(int j =0; j<n; j++){
    if((i&(1<<j))){
        order++;
        if(lcm == 0){
            lcm = 1LL*coins[j];
        } else {
            lcm = 1LL*lcm*coins[j]/gcd(lcm,coins[j]);
        }
    }
    }
    if(order%2 == 0){
        correctedcount -= mid/lcm;
    } else {
        correctedcount += mid/lcm;
    }
    }
    return correctedcount;
}
    long long findKthSmallest(vector<int>& coins, int k) {
     ll result = -1;
     ll lo = 1;
     ll hi = 1LL*(*max_element(coins.begin(),coins.end()))*k;
while(lo<=hi){
    ll mid = lo+(hi-lo)/2;
    if(k <= countSmaller(coins,mid)){
        result = mid;
        hi = mid-1;
    } else {
        lo = mid+1;
    }
}
return result;
    }
};