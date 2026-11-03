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
bool solve(TreeNode* s,TreeNode* t){
    if(s == nullptr && t == nullptr) return true;
    if(s!= nullptr && t == nullptr) return false;
    if(s == nullptr && t != nullptr) return false;
    if(s->val != t->val) return false;
    bool l = solve(s->left,t->left);
    bool r = solve(s->right,t->right);
    return l&&r;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr && subRoot != nullptr) return false;
        if(solve(root,subRoot)) return true;
        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);
        return l || r;
    }
};