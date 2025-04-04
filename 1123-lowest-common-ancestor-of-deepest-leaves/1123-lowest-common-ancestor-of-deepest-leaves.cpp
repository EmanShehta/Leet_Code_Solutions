/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = helper(node->left);
        auto right = helper(node->right);

        if (left.first == right.first)
            return {left.first + 1, node};
        else if (left.first > right.first)
            return {left.first + 1, left.second};
        else
            return {right.first + 1, right.second};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
};