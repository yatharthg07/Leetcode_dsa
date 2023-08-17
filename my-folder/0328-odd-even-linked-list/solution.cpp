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
        ListNode* tail=head;
        ListNode* temp=head;
        int len=1;
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return head;
        }
        while(tail->next!=NULL)
        {
            tail=tail->next;
            len++;
        }
        len=len/2;
        while(len--)
        {
            tail->next=temp->next;
            temp->next=temp->next->next;
            tail->next->next=NULL;
            tail=tail->next;
            temp=temp->next;
        }
        return head;        
    }
};
