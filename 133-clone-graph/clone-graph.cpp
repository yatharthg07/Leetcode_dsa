/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
                if (node == NULL)
            return NULL;

        unordered_map<Node*,Node*> clone;
        queue<Node*> q;
        q.push(node);
        clone[node]=new Node(node->val);
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            for(auto it:curr->neighbors)
            {
                if(clone.find(it)==clone.end())
                {
                    auto newnode=new Node(it->val);
                    clone[it]=newnode;
                    q.push(it);
                }
                clone[curr]->neighbors.push_back(clone[it]);
            }        
        }
        return clone[node];
        
    }
};