/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* lcs(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root == nullptr) return nullptr;
    if(root->val == p->val || root->val == q->val) return root;
    TreeNode* l = lcs(root->left,p,q);
    TreeNode* r = lcs(root->right,p,q);
    if(l != nullptr && r != nullptr) return root;
    if(l != nullptr && r == nullptr) return l;
    if(l == nullptr && r != nullptr) return r;
    return nullptr;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcs(root,p,q);
    }
};