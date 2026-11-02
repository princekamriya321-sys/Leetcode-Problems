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
vector<vector<int>>ans;
void solve(TreeNode* root,int targetSum,vector<int>&arr){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr){
        if(root->val == targetSum){
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
        }
        return;
    }
    arr.push_back(root->val);
    solve(root->left,targetSum-root->val,arr);
    arr.pop_back();
    arr.push_back(root->val);
    solve(root->right,targetSum-root->val,arr);
    arr.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr;
        solve(root,targetSum,arr);
        return ans;
    }
};