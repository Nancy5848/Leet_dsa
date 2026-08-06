class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {
        if (root == NULL)
            return;

        result.push_back(root->val);   // Visit Root
        preorder(root->left);          // Traverse Left
        preorder(root->right);         // Traverse Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};