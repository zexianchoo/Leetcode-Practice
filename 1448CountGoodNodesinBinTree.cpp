/* Created on 02 04 2024 - 08:58PM */ 
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
    void dfs(int& count, int max_val, TreeNode* root) {
        if (root == NULL) { return; }
        
        // increment global count if this is greater or equal to max_val:
        if (root->val >= max_val) { count += 1; }
        // update max val
        max_val = max(root->val, max_val);
        dfs(count, max_val, root->left);
        dfs(count, max_val, root->right);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(count, INT_MIN, root);
        return count;
    }
};
