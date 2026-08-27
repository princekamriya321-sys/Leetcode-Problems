class Solution {
public:
vector<int> parent;
vector<int> rank;
int n;
int find(int x){
    if(parent[x] == x) return x;
    int temp = find(parent[x]);
    parent[x] = temp;
    return temp;
}
void Union(int x,int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    if(rank[px] > rank[py]){
        parent[py] = px;
    } else if(rank[py] > rank[px]){
        parent[px] = py;
    } else {
        parent[py] = px;
        rank[px]++;
    }
    return;
}
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
       parent.resize(n);
       rank.resize(n);
       for(int i = 0; i<n; i++){
        parent[i] = i;
        rank[i] = 1;
       }
       for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                Union(i,j);
            }
        }
       }
       int ans = 0;
       for(int i =0; i<n; i++){
        if(parent[i] == i){
            ans++;
        }
       }
       return n - ans;
    }
};