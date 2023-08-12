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
    bool isPalindrome(ListNode* head) {
                if(head==NULL)
        {
            return false;
        }
        ListNode* fs=head;
        ListNode* sl=head;

        while(fs->next!=NULL&&fs->next->next!=NULL)
        {
            sl=sl->next;
            fs=fs->next->next;
        }
        sl->next=reverseList(sl->next);
        sl=sl->next;
        fs=head;
        while(sl!=NULL)
        {
            if(sl->val!=fs->val)
            {
                return false;
            }
            sl=sl->next;
            fs=fs->next;
        }
        return true;

        
    }
};
