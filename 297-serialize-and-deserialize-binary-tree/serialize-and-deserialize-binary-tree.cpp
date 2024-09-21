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
    string serializedResult = "";
    vector<string> deserializedResult;
    int index;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serializedResult = "";
        serializeDFS(root);
        return serializedResult;
    }

    void serializeDFS(TreeNode* node){
        if(node == nullptr){
            serializedResult += "N,";
            return;
        }

        serializedResult += to_string(node->val) +",";
        serializeDFS(node->left);
        serializeDFS(node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp = "";
        deserializedResult.clear();
        index = 0;
        for(int i=0; i<data.length(); i++){
            if (data[i] == ','){
                deserializedResult.push_back(temp);
                temp = "";
            }else{
                temp += data[i];
            }
        }
        return deserializedDFS();
    }

    TreeNode* deserializedDFS(){
        if (deserializedResult[index] == "N"){
            index += 1;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(deserializedResult[index]));
        index += 1;
        node->left = deserializedDFS();
        node->right= deserializedDFS();
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));