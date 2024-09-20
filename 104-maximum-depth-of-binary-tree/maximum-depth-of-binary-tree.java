/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    // BFS recursive
    // public int maxDepth(TreeNode root) {
    //     if (root == null) return 0;
    //     return (1 + Math.max(maxDepth(root.left), maxDepth(root.right)));
    // }

    // BFS iterative
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int result = 0;
        while(q.size() > 0){
            int len = q.size();
            for(int i = 0; i<len;i++){
                TreeNode temp = q.peek();
                q.remove();
                if (temp.left != null){
                    q.add(temp.left);
                }
                if (temp.right  != null){
                    q.add(temp.right);
                }
            }
            result += 1;
        }
        return result;
    }

    // DFS iterative
    // int maxDepth(TreeNode* root) {
    //     stack<pair<TreeNode*, int>> s;
    //     pair<TreeNode*, int> head (root, 1);
    //     s.push(head);
    //     int result = 0;
    //     while (s.size()){
    //         pair<TreeNode*, int> temp = s.top();
    //         s.pop();
    //         if(temp.first){
    //             if(temp.first->left){
    //                 pair<TreeNode*, int> t (temp.first->left, 1 + temp.second);
    //                 s.push(t);
    //             }
    //             if(temp.first->right){
    //                 pair<TreeNode*, int> t (temp.first->right, 1 + temp.second);
    //                 s.push(t);
    //             }          
    //             result = max(result, temp.second);
    //         }
    //     }
    //     return result;
    // }
}