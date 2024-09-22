import java.util.PriorityQueue;
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i: stones) pq.add(i);
        while (pq.size() > 1){
            int a = pq.peek();
            pq.remove();
            int b = pq.peek();
            pq.remove();
            if (a > b) pq.add (a - b);
        }
        pq.add(0);
        return Math.abs(pq.peek());
    }
}