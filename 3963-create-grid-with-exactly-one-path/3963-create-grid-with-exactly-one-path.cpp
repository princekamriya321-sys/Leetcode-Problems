class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<vector<char>>ch(m,vector<char>(n,'#'));
       for(int j = 0; j<n; j++){
        ch[0][j] = '.';
       }
       for(int i =1; i<m; i++){
        ch[i][n-1] = '.';
       }
       vector<string> s;
       for(int i =0; i<m; i++){
       string t = "";
        for(int j =0; j<n; j++){
          t += ch[i][j];
        }
        s.push_back(t);
       }
return s;
    }
};