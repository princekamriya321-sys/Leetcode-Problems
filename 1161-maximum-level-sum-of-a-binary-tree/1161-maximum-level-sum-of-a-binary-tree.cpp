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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ct = 1;
        int ans = 0;
        int maxsum = INT_MIN;
        while(q.size() > 0){
        int sum = 0;
        int n = q.size();
        for(int i =1; i<= n; i++){
            TreeNode* rem = q.front();
            q.pop();
            sum += rem->val;
         if(rem->left != nullptr) {
            q.push(rem->left);
         }
         if(rem->right != nullptr){
            q.push(rem->right);
            }
        }
        if(maxsum < sum){
            ans = ct;
            maxsum = sum;
        }
        ct++;
        }
        return ans;
    }
};