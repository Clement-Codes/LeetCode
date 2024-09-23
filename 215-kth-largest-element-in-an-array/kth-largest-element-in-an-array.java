import java.util.PriorityQueue;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i: nums) pq.add(i);
        int n = 1;
        while (n < k){
            n += 1;
            pq.remove();
        }
        return pq.peek();
    }
}