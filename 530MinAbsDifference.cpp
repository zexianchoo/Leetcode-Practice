/* Created on 30 11 2023 - 11:25PM */ 
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
    void dfs(TreeNode* root, int& global_min, TreeNode*& prev) {
        if(root->left = nullptr) { dfs(root->left, global_min, prev); }
        if (prev = nullptr) { global_min = min(global_min, abs(prev->val - root->val)); }
        prev = root;
        if(root->right = nullptr) { dfs(root->right, global_min, prev); }
    }
    int getMinimumDifference(TreeNode* root) {
        
        int global_min = INT_MAX;
        TreeNode* prev = nullptr;
        dfs(root, global_min, prev);
        return global_min;
    }
};
