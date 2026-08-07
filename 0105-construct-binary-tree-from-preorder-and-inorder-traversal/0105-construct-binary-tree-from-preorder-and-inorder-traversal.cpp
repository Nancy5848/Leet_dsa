class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right)
            return NULL;

        // Root node
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int index = mp[rootValue];

        // Build left subtree
        root->left = build(preorder, inorder, left, index - 1);

        // Build right subtree
        root->right = build(preorder, inorder, index + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};