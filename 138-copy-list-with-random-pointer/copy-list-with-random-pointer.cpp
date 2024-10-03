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
        unordered_map<Node*,Node*> mp;
        auto temp=head;
        while(temp!=NULL)
        {
            Node* newnode=new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->next) mp[temp]->next=mp[temp->next];
            else mp[temp]->next=NULL;
            if(temp->random) mp[temp]->random=mp[temp->random];
            else mp[temp]->random=NULL;
            temp=temp->next;
        }
        return mp[head];
        
    }
};