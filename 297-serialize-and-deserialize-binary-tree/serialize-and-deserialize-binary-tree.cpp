class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "N";
        }
        string temp = to_string(root->val);
        temp += ',' + serialize(root->left);
        temp += ',' + serialize(root->right);
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Split the data string into tokens using a stringstream.
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Use an index to keep track of the current position in tokens.
        int idx = 0;
        return deserializeHelper(tokens, idx);
    }

private:
    // Helper function for deserialization.
    TreeNode* deserializeHelper(vector<string>& tokens, int& idx) {
        // If we reach the end of tokens or encounter "N", return NULL.
        if (idx >= tokens.size() || tokens[idx] == "N") {
            idx++;
            return NULL;
        }

        // Create a new node with the current value.
        int val = stoi(tokens[idx++]);
        TreeNode* node = new TreeNode(val);

        // Recursively build the left and right subtrees.
        node->left = deserializeHelper(tokens, idx);
        node->right = deserializeHelper(tokens, idx);
        return node;
    }
};
