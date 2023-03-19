class Solution {
public:
    int sumNumbers(TreeNode* root, int vale = 0) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return vale + root->val;
        }

        int sum = 0;
        sum += sumNumbers(root->left, (vale+root->val)*10) + sumNumbers(root->right, (vale+root->val)*10);
        
        return sum;
    }
};
