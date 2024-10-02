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


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1)
        {
            return head;
        }
        auto it=head;
        ListNode* prev=NULL;
        while(it!=NULL)
        {
            auto kth=it;
            for(int i=0;i<k-1;i++)
            {
                kth=kth->next;
                if(kth==NULL)
                {
                    if(prev) prev->next=it;
                    return head;
                }
            }
            auto nxt=kth->next;
            kth->next=NULL;
            reverseList(it);
            if(!prev) head=kth;
            else prev->next=kth;
            prev=it;
            it=nxt;            
        }
        return head;
        
    }
};