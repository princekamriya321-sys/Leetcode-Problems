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
        vector<int> ans;
        void inorder(TreeNode* root){
            if(root == nullptr) return;
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        TreeNode* temp = root;
        inorder(temp);
        for(int i = 0; i<ans.size(); i++){
            k--;
            if(k == 0) return ans[i];
        }
        return ans[ans.size()-1];
    }
};