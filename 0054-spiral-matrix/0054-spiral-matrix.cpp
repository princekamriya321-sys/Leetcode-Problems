class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        int rsteps = n-1;
        int i =0;
        int j =0;
        int csteps = m-1;
        vector<int> ans;
        while(rsteps>=1 && csteps>=1){
         for(int k =0; k<csteps; k++){
            ans.push_back(matrix[i][j]);
            j++;
         }
         for(int k =0; k<rsteps; k++){
            ans.push_back(matrix[i][j]);
            i++;
         }
         for(int k =0; k<csteps; k++){
            ans.push_back(matrix[i][j]);
            j--;
         }
         for(int k =0; k<rsteps; k++){
            ans.push_back(matrix[i][j]);
            i--;
         }
         i++;
         j++;
         rsteps -= 2;
         csteps -= 2;
        }
if(rsteps == 0){
    for(int k = 0; k<=csteps; k++){
        ans.push_back(matrix[i][j]);
        j++;
    }
} else if(csteps == 0){
    for(int k = 0; k<=rsteps; k++){
        ans.push_back(matrix[i][j]);
        i++;
    }
}
return ans;
    }
};