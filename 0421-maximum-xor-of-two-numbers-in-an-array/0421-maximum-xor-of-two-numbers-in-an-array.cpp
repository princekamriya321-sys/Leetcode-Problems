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
        curr = curr->children[bit];
    }
}
int search(int num){
    Node* curr = root;
    int ans = 0;
    for(int i = 31; i>=0; i--){
        int bit = (num>>i)&1;
        if(curr->children[1-bit] != nullptr){
            ans += (1<<i)*1;
            curr = curr->children[1-bit];
        } else {
            ans += (1<<i)*0;
            curr = curr->children[bit];
        }
    }
    return ans;
}
};
    int findMaximumXOR(vector<int>& nums) {
         Trie trie;
        int n = nums.size();
        for(int i =0; i<n; i++){
            trie.insert(nums[i]);
        }
        int ans= 0;
        for(int v: nums){
            ans = max(ans,trie.search(v));
        }
        return ans;
    }
};