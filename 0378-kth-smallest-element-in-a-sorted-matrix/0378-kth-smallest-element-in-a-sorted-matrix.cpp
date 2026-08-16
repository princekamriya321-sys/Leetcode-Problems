class Solution {
public:
int func(vector<vector<int>>&matrix,int m){
    int ct = 0;
    int n = matrix.size();
    int i = 0;
    int j = n-1;
    while(i<n && j>=0){
        if(matrix[i][j] > m){
            j--;
        } else {
            ct += j+1;
            i++;
        }
    }
    return ct;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        while(lo<hi){
    int m = lo + (hi-lo)/2;
    int ct = func(matrix,m);
    if(ct < k){
        lo = m+1;
    } else {
        hi = m;
    }
        }
return lo;
    }
};