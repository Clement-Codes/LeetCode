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
    int preprocessing(TreeNode curr, int level, HashMap<Integer, Integer> levels, HashMap<Integer, Integer> heights, HashMap<Integer, int[]> maxheights){
        if (curr == null) return 0;
        int height = 1 + Math.max(preprocessing(curr.left, level + 1, levels, heights, maxheights), preprocessing(curr.right, level + 1, levels, heights, maxheights));
        levels.put(curr.val, level);
        heights.put(curr.val, height);
        if (! maxheights.containsKey(level)) maxheights.put(level, new int[]{0, 0});
        if (height > maxheights.get(level)[0]){
            maxheights.get(level)[1] = maxheights.get(level)[0] ;
            maxheights.get(level)[0] = height;
        }
        else if (height > maxheights.get(level)[1]){
            maxheights.get(level)[1] = height;
        }
        return height;
    }
    
    public int[] treeQueries(TreeNode root, int[] queries) {
        HashMap<Integer, Integer> levels = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> heights = new HashMap<Integer, Integer>();
        List<Integer> result = new ArrayList<Integer>();
        HashMap<Integer, int[]> maxheights = new HashMap<Integer, int[]>();
        preprocessing(root, 0, levels, heights, maxheights);
        for (int i: queries){
            int temp_level = levels.get(i);
            int temp_height = heights.get(i);
            result.add((temp_height == maxheights.get(temp_level)[0] ? maxheights.get(temp_level)[1] : maxheights.get(temp_level)[0]) + temp_level - 1);
        }
        Integer r[] = new Integer[result.size()];
        r = result.toArray(r);
        return Arrays.stream(r).mapToInt(Integer:: intValue).toArray();
    }
}