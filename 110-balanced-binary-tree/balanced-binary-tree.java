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
class Solution {
    public boolean isBalanced(TreeNode root) {
        return isBalancedDFS(root).getKey();
    }

    Pair<Boolean, Integer> isBalancedDFS(TreeNode root){
        if (root == null){
            Pair<Boolean,Integer> temp = new Pair<Boolean,Integer>(true, 0);
            return temp;
        }

        Pair<Boolean,Integer> left = isBalancedDFS(root.left);
        Pair<Boolean,Integer> right = isBalancedDFS(root.right);
        boolean balanced = Math.abs(left.getValue() - right.getValue()) <= 1 && left.getKey() && right.getKey() ? true : false;
        Pair<Boolean, Integer> result  = new Pair<Boolean,Integer>(balanced, 1 + Math.max(left.getValue(), right.getValue()));
        return result;
    }
}