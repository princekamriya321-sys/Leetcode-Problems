class Solution {
public:
vector<int> func1(vector<int>&height){
    int n = height.size();
    vector<int> pmax(height.size());
    pmax[0] = height[0];
    for(int i =1; i<n; i++){
        pmax[i] = max(pmax[i-1],height[i]);
    }
    return pmax;
}
vector<int> func2(vector<int>&height){
    int n = height.size();
    vector<int> smax(height.size());
    smax[n-1] = height[n-1];
    for(int i =n-2; i>=0; i--){
        smax[i] = max(smax[i+1],height[i]);
    }
    return smax;
}
    int trap(vector<int>& height) {
     int n = height.size();
     vector<int> Pmax = func1(height);
     vector<int> Smax = func2(height);   
     int ans = 0;
     for(int i =1; i<n-1; i++){
      int contri = min(Pmax[i-1],Smax[i+1]) - height[i];
      if(contri > 0){
        ans += contri;
      }
     }
     return ans;
    }
};