class Solution {
public:
  int ans = 0;
  void mergesort(vector<int>&prices,int s,int m,int e){
      vector<int> temp(e-s+1);
      int p1 = s;
      int p2 = m+1;
      int p3 = 0;
      while(p1<=m && p2<=e){
        long long a = prices[p1];
        long long b  = 1LL*2*prices[p2];
          if(a>b){
              ans += m-p1+1;
              p2++;
          } else {
              p1++;
          }
      }
      p1 = s;
      p2 = m+1;
      while(p1<=m && p2<=e){
          if(prices[p1] < prices[p2]){
              temp[p3] = prices[p1];
              p1++;
              p3++;
          } else {
              temp[p3] = prices[p2];
              p2++;
              p3++;
          }
      }
      while(p1<=m){
          temp[p3] = prices[p1];
          p1++;
          p3++;
      }
      while(p2<=e){
          temp[p3] = prices[p2];
          p2++;
          p3++;
      }
      for(int i =0; i<temp.size(); i++){
          prices[i+s] = temp[i];
      }
  }
  void merge(vector<int> &prices,int s,int e){
     if(s>= e) return;
     int m = s + (e-s)/2;
     merge(prices,s,m);
     merge(prices,m+1,e);
     mergesort(prices,s,m,e);
  }
    int reversePairs(vector<int>& nums) {
         int n = nums.size();
   merge(nums,0,n-1);
   return ans;
    }
};