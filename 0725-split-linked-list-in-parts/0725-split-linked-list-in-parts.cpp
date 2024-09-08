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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode * temp=head;
        int len=0;
        while(temp!=nullptr)
        {
            len++;
            temp=temp->next;
            
        }
        int partsz=len/k;
        int extrasz=len%k;
        vector<ListNode*>res(k,nullptr);
        ListNode* curr=head;
        for(int i=0;i<k&&curr!=nullptr;i++)
        {
            res[i]=curr;
            int currpartsz=partsz+(extrasz>0?1:0);
            extrasz--;
            for(int j=1;j<currpartsz;j++)
            {
                curr=curr->next;
            }
            ListNode * next=curr->next;
            curr->next=nullptr;
            curr=next;
        }
        return res;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();