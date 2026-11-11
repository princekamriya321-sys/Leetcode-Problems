class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = min(costBoth,cost1+cost2);
        long long need = min(need1,need2);
        long long ans = 1LL*cost*need;
        ans += 1LL*(need1-need)*(min(cost1,costBoth));
        ans += 1LL*(need2-need)*(min(cost2,costBoth));
        return ans;
    }
};