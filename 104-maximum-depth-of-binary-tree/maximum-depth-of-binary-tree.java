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
    // public int maxDepth(TreeNode root) {
    //     if (root == null) return 0;
    //     Queue<TreeNode> q = new LinkedList<>();
    //     q.add(root);
    //     int result = 0;
    //     while(q.size() > 0){
    //         int len = q.size();
    //         for(int i = 0; i<len;i++){
    //             TreeNode temp = q.peek();
    //             q.remove();
    //             if (temp.left != null){
    //                 q.add(temp.left);
    //             }
    //             if (temp.right  != null){
    //                 q.add(temp.right);
    //             }
    //         }
    //         result += 1;
    //     }
    //     return result;
    // }

    // DFS iterative
    public int maxDepth(TreeNode root) {
        Stack<Pair<TreeNode, Integer>> s = new Stack<>();
        Pair<TreeNode, Integer> head  = new Pair<TreeNode, Integer>(root, 1);
        s.push(head);
        int result = 0;
        while (s.size() > 0 ){
            Pair<TreeNode, Integer> temp = s.peek();
            s.pop();
            if(temp.getKey() != null){
                if(temp.getKey().left != null){
                    Pair<TreeNode, Integer> t = new Pair<TreeNode, Integer>(temp.getKey().left, 1 + temp.getValue());
                    s.push(t);
                }
                if(temp.getKey().right != null){
                    Pair<TreeNode, Integer> t = new Pair<TreeNode, Integer>(temp.getKey().right, 1 + temp.getValue());
                    s.push(t);
                }          
                result = Math.max(result, temp.getValue());
            }
        }
        return result;
    }
}