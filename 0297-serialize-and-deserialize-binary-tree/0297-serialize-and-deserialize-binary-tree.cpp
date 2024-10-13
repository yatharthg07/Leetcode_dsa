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
        if(root==NULL) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node)
                ans.append(to_string(node->val));
            else
                ans.push_back('#');   
            ans.push_back(',');
            if(node){
                q.push(node->left);
                q.push(node->right);
            }    
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return NULL;
        queue<TreeNode*> q;
        stringstream ss(data);
        string s;
        getline(ss,s,',');
        TreeNode* root=new TreeNode(stoi(s));
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            getline(ss,s,',');
            if(s=="#")
            {
                node->left=NULL;
            }
            else
            {
                TreeNode* leftn=new TreeNode(stoi(s));
                node->left=leftn;
                q.push(leftn);
            }
            getline(ss,s,',');
            if(s=="#")
            {
                node->right=NULL;
            }
            else
            {
                TreeNode* rightn=new TreeNode(stoi(s));
                node->right=rightn;
                q.push(rightn);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));