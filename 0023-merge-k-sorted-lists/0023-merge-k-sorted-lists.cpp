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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        for(int i=1;i<lists.size();i++)
        {
            lists[i]=mergeTwoLists(lists[i-1],lists[i]);
        }
        return lists[lists.size()-1];
        
    }
};