class Solution {
public:
    vector<int> result;

    void postorder(TreeNode* root) {
        if (root == NULL)
            return;

        postorder(root->left);      // Traverse Left
        postorder(root->right);     // Traverse Right
        result.push_back(root->val); // Visit Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return result;
    }
};