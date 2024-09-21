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
    int result;

    public int maxPathSum(TreeNode root) {
        this.result = root.val;
        pathSum(root);
        return result;
    }

    int pathSum(TreeNode node){
        if (node == null) return 0;

        int left = pathSum(node.left);
        int right = pathSum(node.right);
        int leftMax = Math.max(left, 0);
        int rightMax = Math.max(right, 0);

        this.result = Math.max(result, node.val + leftMax + rightMax);
        return node.val + Math.max(leftMax, rightMax);
    }
}