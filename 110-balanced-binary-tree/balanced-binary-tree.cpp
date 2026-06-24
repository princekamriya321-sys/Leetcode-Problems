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
 int helper(TreeNode* root){
        if(root == nullptr) return -1;
        int l = helper(root->left);
        int r = helper(root->right);
       return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
         if(root == nullptr) return true;
  int l = helper(root->left);
  int r = helper(root->right);
  int ht = abs(l-r);
  if(ht > 1) return false;
  return isBalanced(root->left)&&isBalanced(root->right);
    }
};