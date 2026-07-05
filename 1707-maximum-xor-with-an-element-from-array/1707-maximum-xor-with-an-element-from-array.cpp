class Solution {
public:
class Node{
    public:
    Node* children[2];
    Node(){
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
class Trie{
public:
 Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* curr = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(curr->children[bit] == nullptr){
                curr->children[bit] = new Node();
            }
            curr= curr->children[bit];
        }
    }
    int search(int num){
        int ans = 0;
        Node* curr = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(curr->children[1-bit] != nullptr){
                ans += (1<<i);
                curr = curr->children[1-bit];
            } else {
                   curr = curr->children[bit];
            }
        }
        return ans;
    }
};
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
          Trie trie;
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
       int q = queries.size();
       vector<int> ans(q);
       vector<pair<int,pair<int,int>>> oq;
       for(int i =0; i<q; i++){
           oq.push_back({queries[i][1],{queries[i][0],i}});
       }
       sort(oq.begin(),oq.end());
           int j = 0;
       for(int i =0; i<q; i++){
           int a = oq[i].first;
           int x = oq[i].second.first;
           int idx = oq[i].second.second;
           while(j <n && nums[j] <= a){
               trie.insert(nums[j]);
               j++;
           }
           if(j == 0){
               ans [idx] = -1;
           } else {
           ans[idx] = trie.search(x);
           }
       }
        return ans;
    }
};