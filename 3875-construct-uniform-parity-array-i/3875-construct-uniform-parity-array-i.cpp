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
        if(ct1 == n || ct2 == n) return true;
        vector<int> arr1;
        for(int i =0; i<n; i++){
            if(nums1[i] % 2 != 0){
                bool t = false;
                for(int j = i+1; j<n; j++){
                    int val = nums1[i] - nums1[j];
                    if(val%2 == 0){
                        arr1.push_back(val);
                        t = true;
                        break;
                    }
                }
                if(t == true) continue;
                  for(int j = i-1; j>=0; j--){
                    int val = nums1[i] - nums1[j];
                    if(val%2 == 0){
                        arr1.push_back(val);
                        t = true;
                        break;
                    }
                }
                if(t == true) continue;
                break;
            }else {
                arr1.push_back(nums1[i]);
            }
        }
        vector<int> arr2;
          for(int i =0; i<n; i++){
            if(nums1[i] % 2 == 0){
                bool t = false;
                for(int j = i+1; j<n; j++){
                    int val = nums1[i] - nums1[j];
                    if(val%2 != 0){
                        arr2.push_back(val);
                        t = true;
                        break;
                    }
                }
                if(t == true) continue;
                  for(int j = i-1; j>=0; j--){
                    int val = nums1[i] - nums1[j];
                    if(val%2 != 0){
                        arr2.push_back(val);
                        t = true;
                        break;
                    }
                }
                if(t == true) continue;
                break;
            }else {
                arr2.push_back(nums1[i]);
            }
        }
        if(arr1.size() == n || arr2.size() == n) return true;
        return false;
    }
};