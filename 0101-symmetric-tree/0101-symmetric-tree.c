/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    
    // Both nodes are NULL
    if (left == NULL && right == NULL) {
        return true;
    }

    // One node is NULL and the other is not
    if (left == NULL || right == NULL) {
        return false;
    }

    // Values are different
    if (left->val != right->val) {
        return false;
    }

    // Compare opposite sides
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}