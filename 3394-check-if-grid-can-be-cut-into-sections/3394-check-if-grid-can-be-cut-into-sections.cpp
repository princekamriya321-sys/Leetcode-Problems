class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>results_x;
        vector<vector<int>>results_y;
        vector<vector<int>> intervals_x;
        vector<vector<int>> intervals_y;
        for(int i =0; i<rectangles.size(); i++){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            intervals_x.push_back({x1,x2});
            intervals_y.push_back({y1,y2});
        }
        sort( intervals_x.begin(), intervals_x.end(),[](auto &a,auto &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        sort(intervals_y.begin(),intervals_y.end(),[](auto &a,auto &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        results_x.push_back(intervals_x[0]);
        for(int i = 1; i<rectangles.size(); i++){
            int x =  intervals_x[i][0];
            int y =  intervals_x[i][1];
            int xo = results_x.back()[0];
            int yo = results_x.back()[1];
            if(yo > x){
               results_x.back()[1] = max(yo,y);
            } else {
                results_x.push_back({x,y});
            }
        }
        results_y.push_back(intervals_y[0]);
        for(int i = 1; i<rectangles.size(); i++){
            int x =  intervals_y[i][0];
            int y =  intervals_y[i][1];
            int xo = results_y.back()[0];
            int yo = results_y.back()[1];
            if(yo > x){
               results_y.back()[1] = max(yo,y);
            } else {
                results_y.push_back({x,y});
            }
        }
          if(results_x.size() >=3 || results_y.size()>=3) return true;
          return false;
    }
};