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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        ListNode *preslow;
        
        while(fast && fast->next){
            preslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << preslow->val << ", " << slow->val << endl;
        
        TreeNode* root = new TreeNode(slow->val);
        preslow->next = nullptr;
        root->left = (slow == head) ? nullptr : sortedListToBST(head);
        
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};