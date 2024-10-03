/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto it=head;
        //inserting at alternate positions
        while(it)
        {
            auto node=new Node(it->val);
            node->next=it->next;
            it->next=node;
            it=it->next->next;
        }
        //assigning random pointers
        it=head;
        while(it)
        {
            if(it->random)it->next->random=it->random->next;
            else it->next->random=NULL;
            it=it->next->next;
        }
        //assigining next and making orignal list intact
        Node* dummy=new Node(-1);
        auto temp=dummy;
        it=head;
        while(it)
        {   
            temp->next=it->next;
            it->next=it->next->next;
            temp=temp->next;
            temp->next=NULL;
            it=it->next;

        }
        return dummy->next;


        
    }
};