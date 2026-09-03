class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int n= nums1.size();
        int ct1 = 0;
        int ct2 = 0;
        for(int v: nums1){
            if(v%2 == 0){
                ct1++;
            } else {
                ct2++;
        }
        }
        sort(nums1.begin(),nums1.end());
        if(ct1 == n || ct2 == n) return true;
      if(nums1[0]%2 == 0) return false;
      return true;
    }
};