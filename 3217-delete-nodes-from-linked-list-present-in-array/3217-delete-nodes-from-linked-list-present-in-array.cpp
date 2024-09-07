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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode * demo=new ListNode(0);
        demo->next=head;
        ListNode* curr=demo;
        while(curr->next!=nullptr)
        {
           if(st.find(curr->next->val)!=st.end())
           {
               curr->next=curr->next->next;
           }
               else
               {
                   curr=curr->next;
               }
           
        }
        return demo->next;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
