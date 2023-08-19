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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head->next==NULL)
        {
            return NULL;
        }
        if(head->next->next==NULL)
        {
            delete (head->next);
            head->next=NULL;
            return head;
        }
        while(fast->next->next!=NULL&&fast->next->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;

        return head;
        
    }
};
