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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }
    int rootVal = postorder[postEnd];
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    int leftSize = rootIndex - inStart;
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1);
    root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
    return root;
}
};