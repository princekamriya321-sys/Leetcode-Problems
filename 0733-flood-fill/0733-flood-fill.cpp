class Solution {
public:
 void dfs(vector<vector<int>>& image,vector<vector<bool>>& vis,int r,int c,int target,int newColor){
        vis[r][c] = true;
        if(r>0 && image[r-1][c] == target && vis[r-1][c] == false){
            image[r-1][c] = newColor;
            dfs(image,vis,r-1,c,target,newColor);
        }
         if(c>0 && image[r][c-1] == target && vis[r][c-1] == false){
            image[r][c-1] = newColor;
            dfs(image,vis,r,c-1,target,newColor);
        }
         if(r<image.size()-1 && image[r+1][c] == target && vis[r+1][c] == false){
            image[r+1][c] = newColor;
            dfs(image,vis,r+1,c,target,newColor);
        }
         if(c<image[0].size()-1 && image[r][c+1] == target && vis[r][c+1] == false){
            image[r][c+1] = newColor;
            dfs(image,vis,r,c+1,target,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int n = image.size();
            int m = image[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
      int k = image[sr][sc];
      image[sr][sc] = color;
    dfs(image,vis,sr,sc,k,color);
    return image;
    }
};