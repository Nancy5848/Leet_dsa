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
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // Calculate the number formed up to the current node
        currentSum = currentSum * 10 + node->val;
        
        // If it's a leaf node, return the accumulated path sum
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Recursively sum left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};