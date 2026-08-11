class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       vector<pair<int,int>>arr;
        int n = pairs.size();
        for(int i =0; i<n; i++){
            arr.push_back({pairs[i][1],pairs[i][0]});
        }
        sort(arr.begin(),arr.end());
        int ans = 1;
        int last = arr[0].first;
        for(int i =1; i<n; i++){
    if(arr[i].second > last){
    ans++;
    last  = arr[i].first;
}
        }
        return ans;
    }
};