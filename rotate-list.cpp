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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        int len=0;
        auto it1=head;
        ListNode* endd;
        while(it1!=NULL)
        {
            len++;
            if(it1->next==NULL)
            {
                endd=it1;
            }
            it1=it1->next;
        }
        k=k%len;
        if(k==0)
        {
            return head;
        }
        int cnt=len-k-1;
        it1=head;
        while(cnt--)
        {
            it1=it1->next;
        }
        auto newh=it1->next;
        it1->next=NULL;
        endd->next=head;
        return newh;
    }
};