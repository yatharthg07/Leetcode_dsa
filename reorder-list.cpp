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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=NULL;
        ListNode* next;
        while(head!=NULL)
        {
            next=head->next;
            head->next=temp;
            temp=head;
            head=next;
        }
        return temp;
        
    }

    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return;
        }
        auto temp=head;
        while(temp->next!=NULL)
        {
            temp->next=reverseList(temp->next);
            temp=temp->next;
        }
        return;

        
    }
};