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
    ListNode* deleteDuplicates(ListNode* head) {
        auto it1=head;
        while(it1!=NULL)
        {
            auto it2=it1->next;
            while(it2!=NULL && it2->val==it1->val)
            {
                auto temp=it2;
                it2=it2->next;
                delete temp;            
            }
            it1->next=it2;
            it1=it1->next;
        }   
        return head;
        
    }
};