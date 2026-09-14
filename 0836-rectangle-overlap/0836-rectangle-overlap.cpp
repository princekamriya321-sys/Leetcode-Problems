class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       int x1 = rec1[0];
       int y1 = rec1[1]; 
       int x2 = rec1[2];
       int y2= rec1[3];
       int t1 = rec2[0];
       int s1 = rec2[1]; 
       int t2 = rec2[2];
       int s2= rec2[3];
   if(x2 <= t1 || t2 <= x1)
    return false;
   if(s2 <= y1 || y2 <= s1)
    return false;

 return true;
    }
};