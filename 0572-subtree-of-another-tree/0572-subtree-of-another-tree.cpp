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
bool solve(TreeNode* root,TreeNode* subRoot){
    if(root == nullptr && subRoot == nullptr) return true;
    if(root == nullptr && subRoot != nullptr) return false;
    if(root != nullptr && subRoot == nullptr) return false;
    bool l = solve(root->left,subRoot->left);
    bool r = solve(root->right,subRoot->right);
    return root->val == subRoot->val && (l && r);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root == nullptr) return false;
        if(root->val == subRoot->val){
            if(solve(root,subRoot)) return true;
        }
            bool l = isSubtree(root->left,subRoot);
            bool r = isSubtree(root->right,subRoot);
            return (l || r);
        }
};