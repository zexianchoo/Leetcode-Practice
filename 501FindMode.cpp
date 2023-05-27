/* Created on 28 05 2023 - 04:15AM */ 
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
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    std::vector<int> res;
    void inOrderTraversal(TreeNode* root) {
        
        if (root == nullptr) { return; }
        inOrderTraversal(root->left);
        if (precursor == root->val) currFreq++;
        else currFreq = 1;
        if (currFreq > maxFreq)
        {// Current node value has higher frequency than any previous visited
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }
        else if (currFreq == maxFreq)
        {// Current node value has a frequency equal to the highest of previous visited
            res.push_back(root->val);
        }
        precursor = root->val; // Update the precursor
        inOrderTraversal(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        // do an inorder traversal which allows for successive counting easily
        inOrderTraversal(root);
        return res;
    }
};
