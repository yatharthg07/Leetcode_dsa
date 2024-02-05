/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode*> q;
        
        string s="";
        if(root==NULL)
        {
            s+='#';
            return s;
            
        }
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream stream(data);
        string token;
        if(data[0]=='#')
        {
            return NULL;
        }
        int flag=0;
        queue<TreeNode *> q;
        string med;
        getline(stream ,token ,',');
        TreeNode* root=new TreeNode(stoi(token));

        q.push(root);

        while(!q.empty())
        {   TreeNode* temp=q.front();
            q.pop();
            getline(stream ,token ,',');
            if(token=="#")
                temp->left=NULL;
            else{
                TreeNode* leftnode= new TreeNode();
  
                leftnode->val=stoi(token);
                temp->left = leftnode; 
                q.push(temp->left);
            }   
            getline(stream ,token ,',');  
            if(token=="#")
                temp->right=NULL;
            else{
                TreeNode* rightnode= new TreeNode();
                rightnode->val=stoi(token);
                temp->right =  rightnode   ; 
                q.push(temp->right);    }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
