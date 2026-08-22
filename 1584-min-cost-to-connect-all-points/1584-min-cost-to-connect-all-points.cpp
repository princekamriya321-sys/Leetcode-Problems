class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i =0; i<n; i++){
            int xi = points[i][0];
            int yi = points[i][1];
            for(int j=i+1; j<n; j++){
                int xo = points[j][0];
                int yo = points[j][1];
                int wt = abs(xo-xi) + abs(yo-yi);
                graph[i].push_back({j,wt});
                graph[j].push_back({i,wt});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> ans(n,INT_MAX);
        pq.push({0,0});
        while(pq.size()>0){
            auto rem = pq.top();
            int wt = rem.first;
            int vtx = rem.second;
            pq.pop();
            if(ans[vtx] != INT_MAX){
                continue;
            } else {
                ans[vtx] = wt;
            }
            for(auto v: graph[vtx]){
                if(ans[v.first] != INT_MAX) continue;
                pq.push({v.second,v.first});
            }
        }
        int sum = 0;
        for(int i =0; i<n; i++) sum += ans[i];
        return sum;
    }
};