class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(n+m);
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        while(p1<m && p2<n){
            if(nums1[p1] < nums2[p2]){
                temp[p3] = nums1[p1];
                p1++;
                p3++;
            } else {
                temp[p3] = nums2[p2];
                p3++;
                p2++;
            }
        }
        while(p1<m){
            temp[p3] = nums1[p1];
            p1++;
            p3++;
        }
        while(p2<n){
            temp[p3] = nums2[p2];
            p2++;
            p3++;
        }
        for(int i=0; i<temp.size(); i++){
            nums1[i] = temp[i];
        }
    }
};