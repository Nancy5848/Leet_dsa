class Solution {
public:

    bool checkBST(TreeNode* root, long long minValue, long long maxValue) {

        // Empty tree is a valid BST
        if (root == nullptr)
            return true;

        // Current node must be strictly within the allowed range
        if (root->val <= minValue || root->val >= maxValue)
            return false;

        // Check left subtree
        bool left = checkBST(root->left, minValue, root->val);

        // Check right subtree
        bool right = checkBST(root->right, root->val, maxValue);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};