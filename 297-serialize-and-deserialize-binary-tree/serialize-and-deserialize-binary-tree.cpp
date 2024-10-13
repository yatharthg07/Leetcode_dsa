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
        if (data == "N") return NULL;
        
        // Step 1: Tokenize the serialized string
        vector<string> tokens;
        int i = 0;
        while (i < data.size()) {
            int pos = data.find(',', i);
            if (pos == string::npos) pos = data.size();
            tokens.push_back(data.substr(i, pos - i));
            i = pos + 1;
        }

        if (tokens.empty()) return NULL;

        // Step 2: Initialize variables
        stack<pair<TreeNode*, int>> st; // Pair of node and state (0: left, 1: right, 2: done)
        int idx = 0;

        // Create root node
        TreeNode* root = new TreeNode(stoi(tokens[idx++]));
        st.push({root, 0});

        // Step 3: Iterate over tokens
        while (idx < tokens.size() && !st.empty()) {
            auto& [node, state] = st.top();

            if (state == 0) {
                // Process left child
                if (tokens[idx] != "N") {
                    TreeNode* leftChild = new TreeNode(stoi(tokens[idx]));
                    node->left = leftChild;
                    st.top().second = 1; // Update state to process right child next
                    st.push({leftChild, 0}); // Push left child onto stack
                } else {
                    node->left = NULL;
                    st.top().second = 1; // Update state to process right child next
                }
                idx++;
            } else if (state == 1) {
                // Process right child
                if (tokens[idx] != "N") {
                    TreeNode* rightChild = new TreeNode(stoi(tokens[idx]));
                    node->right = rightChild;
                    st.top().second = 2; // Update state to done
                    st.push({rightChild, 0}); // Push right child onto stack
                } else {
                    node->right = NULL;
                    st.top().second = 2; // Update state to done
                }
                idx++;
            } else {
                // Both children have been processed; pop the node
                st.pop();
            }
        }

        return root;
    }
};
