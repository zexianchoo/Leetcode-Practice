/* Created on 02 10 2023 - 00:02AM */ 
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
    int getHeight(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) { return true; }
        return getHeight(root) = -1;
    }
};
