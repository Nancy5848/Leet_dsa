class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right)
            return NULL;

        // Root node
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int index = mp[rootValue];

        // Build right subtree first
        root->right = build(inorder, postorder, index + 1, right);

        // Build left subtree
        root->left = build(inorder, postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};