/* Created on 02 04 2024 - 08:54PM */ 
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
    void dfs(vector<int>& res, TreeNode* root, int depth) {
        if (root == NULL) { return; }
        if (depth > res.size()) {
            res.push_back(root->val);
        }
        dfs(res, root->right, depth + 1);
        dfs(res, root->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(res, root, 1);
        return res;
    }
};
