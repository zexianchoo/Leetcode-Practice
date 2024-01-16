/* Created on 01 12 2023 - 00:10AM */ 
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
    int max_val = -INT_MAX;
    int getLength(TreeNode* root, int& max_val) {
        if (root == nullptr) {
            return -1;
        }
        int best_left = getLength(root->left, max_val) + 1;
        int best_right = getLength(root->right, max_val) + 1;
        max_val = max(max_val, best_left + best_right);
        return max(best_left, best_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getLength(root, max_val);
        return max_val;
    }
};
