class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int[] result = new int[2];
        PriorityQueue<int []> pq = new PriorityQueue<int []>((a, b) -> a[0] - b[0]);
        int start = 0;
        int end = Integer.MAX_VALUE;
        int currMax = Integer.MIN_VALUE;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.add(new int[]{nums.get(i).get(0), i, 0});
            currMax = Math.max(currMax, nums.get(i).get(0));
        }
        while (pq.size() == nums.size()){
            int[] curr = pq.poll();
            if (end - start > currMax - curr[0]){
                start = curr[0];
                end = currMax;
            }
            if (curr[2] + 1 < nums.get(curr[1]).size()){
                pq.add(new int[]{nums.get(curr[1]).get(curr[2] + 1), curr[1], curr[2] + 1});
                currMax = Math.max(currMax, nums.get(curr[1]).get(curr[2] + 1));
            } 
        }
        result[0] = start;
        result[1] = end;
        return result;
    }
}