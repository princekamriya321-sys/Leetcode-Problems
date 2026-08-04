class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<int> arr(n*n+1);
       for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            arr[grid[i][j]]++;
        }
       } 
       int missingele =0;
       int repeatele = 0;
       for(int i=0; i<arr.size(); i++){
       if(arr[i] > 1){
        repeatele = i;
       }
       if(arr[i] == 0){
        missingele = i;
       }
       }
       return {repeatele,missingele};
    }
};