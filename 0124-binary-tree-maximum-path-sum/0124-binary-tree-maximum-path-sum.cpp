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
    int maxsum;
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        int niche_hi_accha = l + r + root->val;
        int koi_ek_accha = max(l,r) + root->val;
        int mai_hi_accha = root->val;
        maxsum= max({maxsum,niche_hi_accha,koi_ek_accha,mai_hi_accha});
        return max(koi_ek_accha,mai_hi_accha);
    }
    int maxPathSum(TreeNode* root) {
         maxsum = INT_MIN;
      int n = helper(root);
      return maxsum;
    }
};