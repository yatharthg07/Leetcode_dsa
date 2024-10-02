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
        auto sl=head;
        auto fs=head->next->next;
        while(fs!=NULL&&fs->next!=NULL)
        {
            sl=sl->next;
            fs=fs->next->next;
        }
        auto it1=head;
        auto it2=reverseList(sl->next);
        sl->next=NULL;
        while(it1!=NULL)
        {
            auto next1=it1->next;
            auto next2=it2->next;
            it1->next=it2;
            if(next1) it2->next=next1;
            it1=next1;
            it2=next2;
        }
        return ;
        
    }
};