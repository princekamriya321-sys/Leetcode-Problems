class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
             vector<pair<int,int>> p;
         int n = arr.size();
         vector<int>ans(n);
         unordered_map<int,int> mp;
         for(int i = 0; i<n; i++){
             p.push_back({arr[i],i});
         }
       sort(p.begin(), p.end());

int rank = 1;

for(int i = 0; i < n; i++) {

    if(mp.find(p[i].first) == mp.end()) {
        mp[p[i].first] = rank++;
    }

    ans[p[i].second] = mp[p[i].first];
}
         return ans;
    }
};