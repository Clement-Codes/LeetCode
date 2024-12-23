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

    public int countSwaps(int[] nums){
        int result = 0;
        int sort_nums[] = nums.clone();
        Arrays.sort(sort_nums);
        HashMap<Integer, Integer> idx_nums = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++)
            idx_nums.put(nums[i], i);
        for (int i = 0; i < nums.length; i++)
        {
            if (sort_nums[i] != nums[i]){
                result++;
                int j = idx_nums.get(sort_nums[i]);
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                idx_nums.put(nums[j], j); 
            }
        }
        return result;
    }

    public int minimumOperations(TreeNode root) {
        Deque<TreeNode> d = new LinkedList<TreeNode>();
        d.addLast(root);
        int result = 0;
        while (d.size() > 0){
            int n = d.size();
            int[] nums = new int[n];
            int ii = 0;
            for (TreeNode t: d){
                nums[ii] = t.val;
                ii++;
            }
            while (n > 0){
                TreeNode temp = d.peekFirst();
                d.removeFirst();
                if (temp.left != null)
                    d.addLast(temp.left);
                if (temp.right != null)
                    d.addLast(temp.right);
                n--;
            }
            result += countSwaps(nums);
        }
        return result;        
    }
}