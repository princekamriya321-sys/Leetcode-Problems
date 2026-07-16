class Solution {
public:
typedef pair<int,int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            queue<P> q;
        vector<int> ans(n,INT_MAX);
        ans[src] = 0;
        vector<vector<pair<int,int>>> graph(n);
        int steps = -1;
        for(int i =0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            graph[u].push_back({v,wt});
        }
        q.push({src,0});
        ans[src] = 0;
        while(q.size()>0 && steps<=k){
            int N = q.size();
            steps++;
            while(N--){
                auto rem = q.front();
                int price = rem.second;
                int node = rem.first;
                q.pop();
                if(ans[node] > price){
                    ans[node] = price;
                }
                for(auto &v: graph[node]){
                    int nbr = v.first;
                    int val = v.second;
                    if(ans[nbr] > val + price){
                        q.push({nbr,val+price});
                    }
                }
            }
        }
        if(ans[dst] == INT_MAX) return -1;
        return ans[dst];
    }
};