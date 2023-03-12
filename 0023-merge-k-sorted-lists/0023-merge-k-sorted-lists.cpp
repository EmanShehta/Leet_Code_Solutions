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
class Solution {
public:
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto& node:lists){
            if(node!=nullptr){
                pq.push({node->val,node});
            }
        }
        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();
            if(node->next!=nullptr){
                pq.push({node->next->val,node->next});
            }
            dummy->next = node;
            dummy = node;
        }
        return head->next;
    }
};