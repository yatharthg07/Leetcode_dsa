/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto it=head;
        while(it!=NULL)
        {
            auto nxt=it->next;
            if(it->child)
            {
                auto newh=flatten(it->child);
                auto it2=newh;
                while(it2->next!=NULL)
                {
                    it2=it2->next;
                }
                newh->prev=it;
                it2->next=nxt;
                if(nxt) nxt->prev=it2;
                it->next=it->child;
                it->child=NULL;
            }
            it=nxt; 
        }
        return head;
    }
};