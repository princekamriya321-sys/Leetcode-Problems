class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                  queue<int> q;
                  vector<int> ans;
    int n = numCourses;
    int p = prerequisites.size();
    vector<int> indegree(n,0);
    vector<vector<int>> graph(n);
    for(int i =0; i<p; i++){
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        graph[u].push_back(v);
        }
    for(int u = 0; u<n; u++){
        for(int v : graph[u]){
            indegree[v]++;
        }
    }
    for(int i =0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(q.size()>0){
        int rem = q.front();
        q.pop();
   ans.push_back(rem);
        for(int v: graph[rem]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
    if(ans.size() != n)
    return {};
      return ans;
        
    }
};