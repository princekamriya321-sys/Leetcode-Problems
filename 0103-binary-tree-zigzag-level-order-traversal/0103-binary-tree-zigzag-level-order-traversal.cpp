/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSI0MCIgaGVpZ2h0PSI0MCIgZmlsbD0ibm9uZSIgdmlld0JveD0iMCAwIDQwIDQwIj48cGF0aCBmaWxsPSIjZWJmMjEyIiBkPSJtMjEuNDY2IDUuMDcxLjAwNCAxMC45MTVjLjAwMSAxLjcyNS0xLjgzNCAyLjgzLTMuMzU4IDIuMDI0TDcuMTcgMTIuMjIzYTE1LjEgMTUuMSAwIDAgMSAzLjEtMy42NGw4LjU4MiA3LjkzMmMuNDU1LjQyIDEuMTcyLS4wMzYuOTg1LS42MjZMMTYuNTA5IDUuNDFhMTUgMTUgMCAwIDEgNC45NTYtLjMzOE0xOC40OTYgMzQuOTI1bC0uMDA1LTEwLjg2YzAtMS43MjQgMS44MzQtMi44MyAzLjM1OS0yLjAyM2wxMC45NDYgNS43OWExNSAxNSAwIDAgMS0zLjExNiAzLjYyNmwtOC41Ny03LjkyMWMtLjQ1NS0uNDItMS4xNzIuMDM1LS45ODUuNjI1bDMuMzE2IDEwLjQ0MWExNSAxNSAwIDAgMS00Ljk0NS4zMjJNMjMuNDkyIDE4Ljg5OCAzMS40NCAxMC4zYTE1IDE1IDAgMCAwLTMuNjQtMy4xMTNsLTUuODA0IDEwLjk3MmMtLjgwNiAxLjUyNC4zIDMuMzU5IDIuMDI0IDMuMzU4bDEwLjkwNS0uMDA1YTE1LjIgMTUuMiAwIDAgMC0uMzI0LTQuOTU4bC0xMC40ODQgMy4zM2MtLjU5LjE4Ny0xLjA0NS0uNTMtLjYyNS0uOTg1TTUuMDcgMTguNTRsMTAuODcyLS4wMDRjMS43MjUgMCAyLjgzIDEuODM0IDIuMDI0IDMuMzU4TDEyLjE5MiAzMi44MWExNSAxNSAwIDAgMS0zLjYyNy0zLjEwM2w3LjkwNi04LjU1M2MuNDItLjQ1NS0uMDM2LTEuMTcyLS42MjYtLjk4NUw1LjQwOCAyMy40ODRhMTUgMTUgMCAwIDEtLjMzNy00Ljk0MyIvPjwvc3ZnPg==$0
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