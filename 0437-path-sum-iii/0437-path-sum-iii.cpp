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
int solve(TreeNode* root,int targetSum,long long sum){
    if(root == nullptr) return 0;
    int count = (targetSum == sum+root->val) ? 1: 0;
   int l =  solve(root->left,targetSum ,sum + root->val);
   int r =  solve(root->right,targetSum ,sum + root->val);
   return l+r + count;
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int ct = solve(root,targetSum,0);
    int l = pathSum(root->left,targetSum);
    int r= pathSum(root->right,targetSum);
    return l + r + ct;
    }
};