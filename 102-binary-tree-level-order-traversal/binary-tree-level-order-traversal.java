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

import java.util.List;
import java.util.ArrayList;
import java.util.Queue;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(q.size()>0){
            List<Integer> temp = new ArrayList<Integer>();
            int l = q.size();
            for (int i = 0; i < l; i++){
                TreeNode node = q.peek();
                q.remove();
                if(node != null){
                    temp.add(node.val);
                    q.add(node.left);
                    q.add(node.right);
                }
            }
            if(temp.size()>0){
                result.add(temp);
            }
        }
        return result;
    }
}