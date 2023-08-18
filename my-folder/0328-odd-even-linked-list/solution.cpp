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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return head;
        }
        ListNode* et=head;
        ListNode* oh=head->next;
        ListNode* ot=head->next;
        while(ot!=NULL && ot->next!=NULL)
        {
            et->next=ot->next;
            et=et->next;
            ot->next=et->next;
            ot=ot->next;
        }
        et->next=oh;
        return head;

    }
};
