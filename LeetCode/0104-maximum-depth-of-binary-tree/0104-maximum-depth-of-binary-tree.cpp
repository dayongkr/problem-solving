/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int result = 0;
    void dfs(TreeNode* node, int depth) {
        result = max(depth, result);
        if (node->left)
            dfs(node->left, depth + 1);
        if (node->right)
            dfs(node->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        if (root)
            dfs(root, 1);
        return result;
    }
};