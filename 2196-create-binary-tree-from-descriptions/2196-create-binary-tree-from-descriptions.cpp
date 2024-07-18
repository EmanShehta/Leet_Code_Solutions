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
   TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> nodeMap;
    unordered_set<int> childNodes;

    // First pass: create nodes and establish parent-child relationships
    for (const auto& desc : descriptions) {
        int parentVal = desc[0]; // Parent node value
        int childVal = desc[1];  // Child node value
        bool isLeft = desc[2];   // Flag indicating if the child is a left child



        // Create parent node if it doesn't exist in the map
        if (nodeMap.find(parentVal) == nodeMap.end()) {
            nodeMap[parentVal] = new TreeNode(parentVal);
        } 

        // Create child node if it doesn't exist in the map
        if (nodeMap.find(childVal) == nodeMap.end()) {
            nodeMap[childVal] = new TreeNode(childVal);
        } 

        // Establish the parent-child relationship
        if (isLeft) {
            nodeMap[parentVal]->left = nodeMap[childVal];
        } else {
            nodeMap[parentVal]->right = nodeMap[childVal];
        }

        // Record the child node in the set
        childNodes.insert(childVal);
    }

    // Second pass: identify the root node
    for (const auto& desc : descriptions) {
        int parentVal = desc[0];
        // The root node is the one that is never a child node
        if (childNodes.find(parentVal) == childNodes.end()) {
            return nodeMap[parentVal];
        }
    }

    return nullptr; // Return null if there is no valid root (edge case)
}

};