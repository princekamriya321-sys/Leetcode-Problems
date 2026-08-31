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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
       unsigned long long maxwidth = 0;
        while(q.size() > 0){
            int n = q.size();
           unsigned long long st = q.front().second;
           unsigned long long end = q.back().second;
            maxwidth = max(maxwidth,end - st+1);
            for(int i = 0; i<n; i++){
                auto curr = q.front();
                q.pop();
                if(curr.first->left != nullptr){
                    q.push({curr.first->left,1LL*2*curr.second+1});
                }
                if(curr.first->right != nullptr){
                    q.push({curr.first->right,1LL*2*curr.second+2});
                }
            }
        }
        return maxwidth;
    }
};