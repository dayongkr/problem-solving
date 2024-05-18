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
    vector<int> s;
    bool result = true;
    void DFS(TreeNode* node, int flag) {
        TreeNode *left = node->left, *right = node->right;
        if (!result)
            return;
        if (!left && !right)
            if (flag) {
                if(s.empty() || s.back() != node->val){
                    result = false;
                    return;
                }
                s.pop_back();
            } else
                s.push_back(node->val);
        if (left)
            DFS(left, flag);
        if (right)
            DFS(right, flag);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        DFS(root1, 0);
        reverse(s.begin(), s.end());
        DFS(root2, 1);
        if(!s.empty()) return false;
        return result;
    }
};