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
    ListNode* mid(ListNode * head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }
    ListNode* merge(ListNode * list1,ListNode* list2)
    {
        ListNode* dummy=new ListNode(0,NULL);
        ListNode* temp=dummy;
        while(list1!=NULL&& list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=NULL)
        {
            temp->next=list1;
        }
        if(list2!=NULL)
        {
            temp->next=list2;
        }
        ListNode* temp1=dummy->next;
        delete dummy;
        return temp1;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode * left=head;
        ListNode * right=mid(head);
        ListNode *temp=right->next;
        right->next=NULL;
        right=temp;
        left=sortList(left);
        right=sortList(right);
        head=merge(left,right);
        return head;

        
    }
};
