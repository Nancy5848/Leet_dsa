class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // If one node is NULL and the other is not
        if (p == NULL || q == NULL)
            return false;

        // If values are different
        if (p->val != q->val)
            return false;

        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};