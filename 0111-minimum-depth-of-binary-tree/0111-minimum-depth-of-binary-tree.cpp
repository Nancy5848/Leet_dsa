class Solution {
public:
    int minDepth(TreeNode* root) {
        // Empty tree
        if (root == NULL)
            return 0;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return 1;

        // Only right child exists
        if (root->left == NULL)
            return 1 + minDepth(root->right);

        // Only left child exists
        if (root->right == NULL)
            return 1 + minDepth(root->left);

        // Both children exist
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};