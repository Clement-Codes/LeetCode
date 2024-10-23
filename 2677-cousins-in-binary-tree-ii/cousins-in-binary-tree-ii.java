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
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        List<Integer> level = new ArrayList<Integer>();
        
        while (q.size() > 0){
            int length = q.size();
            int sum = 0;
            while (length > 0){
                TreeNode temp = q.poll();
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
                sum += temp.val;
                length -= 1;
            }
            level.add(sum);
        }

        Queue<Pair<TreeNode, Integer>> q2 = new LinkedList<Pair<TreeNode, Integer>>();
        q2.add(new Pair<TreeNode, Integer> (root, root.val));
        int curr = 0;
        while (q2.size() > 0){
            int length = q2.size();
            while (length > 0){
                Pair<TreeNode, Integer> temp = q2.poll();
                temp.getKey().val = level.get(curr) - temp.getValue();
                int sibling = 0;
                if (temp.getKey().left != null) sibling += temp.getKey().left.val;
                if (temp.getKey().right != null) sibling += temp.getKey().right.val;
                if (temp.getKey().left != null) q2.add(new Pair<TreeNode, Integer> (temp.getKey().left, sibling));
                if (temp.getKey().right != null) q2.add(new Pair<TreeNode, Integer> (temp.getKey().right, sibling));
                length -= 1;
            }
            curr += 1;
        }
        return root;
    }
}