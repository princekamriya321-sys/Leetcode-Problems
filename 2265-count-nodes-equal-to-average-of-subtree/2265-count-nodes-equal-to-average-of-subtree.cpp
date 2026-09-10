/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans = 0;
pair<int,int> solve(TreeNode* root){
    if(root == nullptr){
        return {0,0};
    }
    auto l = solve(root->left);
    auto r = solve(root->right);
    int ct = l.second + r.second+1;
    int sum = l.first + r.first + root->val;
    if(sum/ct == root->val){
        ans++;
    }
    return {sum,ct};
}
    int averageOfSubtree(TreeNode* root) {
      pair<int,int> arr = solve(root);
       return ans; 
    }
};