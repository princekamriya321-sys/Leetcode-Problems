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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
     if(root == nullptr) return v;
        queue<TreeNode*> q;
        q.push(root);
        int ct = 0;
        while(q.size() > 0){
        vector<int>ans;
            int n = q.size();
            for(int i =1; i<=n; i++){
                TreeNode* rem = q.front();
                q.pop();
                ans.push_back(rem->val);
                if(rem->right != nullptr){
                    q.push(rem->right);
                }
                if(rem->left != nullptr){
                    q.push(rem->left);
                }
            }
            if(ct%2 == 0){
                reverse(ans.begin(),ans.end());
            }
        ct++;
        v.push_back(ans);
        }
        return v; 
    }
};