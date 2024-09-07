/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     bool 
         doesPathMatch(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr || head->val != root->val) return false;
        
return doesPathMatch(head->next, root->left) || doesPathMatch(head->next, root->right);
    }
    
     bool isSubPath(ListNode* head, TreeNode* root) {
       if(root ==nullptr) return false;
         return isSubPath(head,root->left)||isSubPath(head,root->right)||
             doesPathMatch(head,root);
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();