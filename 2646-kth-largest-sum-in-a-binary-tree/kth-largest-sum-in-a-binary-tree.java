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
    public long kthLargestLevelSum(TreeNode root, int k) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        PriorityQueue<Long> pq = new PriorityQueue<Long>();
        q.add(root);
        while(q.size() > 0){
            int l = q.size();
            long s = 0;
            while (l > 0){
                TreeNode temp = q.poll();
                s += temp.val;
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
                l -= 1;
            }
            pq.add(s);
            if (pq.size() > k){
                pq.remove();
            }
        }

        return pq.size() < k ? -1 : pq.peek();
    }
}