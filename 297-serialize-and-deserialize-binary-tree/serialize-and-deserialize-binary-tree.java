/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.Vector;
public class Codec {
    String serializedResult = "";
    Vector<String> deserializedResult = new Vector<String>();
    int index = 0;
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        serializedResult = "";
        serializeDFS(root);
        return serializedResult;
    }

    void serializeDFS(TreeNode node){
        if(node == null){
            serializedResult += "N,";
            return;
        }

        serializedResult += Integer.toString(node.val) +",";
        serializeDFS(node.left);
        serializeDFS(node.right);
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String temp = "";
        deserializedResult.clear();
        index = 0;
        for(int i=0; i<data.length(); i++){
            if (data.charAt(i) == ','){
                deserializedResult.add(temp);
                temp = "";
            }else{
                temp += data.charAt(i);
            }
        }
        return deserializedDFS();
    }
    
    public TreeNode deserializedDFS(){
        if (deserializedResult.get(index).equals("N")){
            index += 1;
            return null;
        }
        TreeNode node = new TreeNode(Integer.valueOf(deserializedResult.get(index)));
        index += 1;
        node.left = deserializedDFS();
        node.right= deserializedDFS();
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));