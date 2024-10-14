class Solution {
    public long maxKelements(int[] nums, int k) {
        long score = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int i: nums)
            pq.add(i);
        while(k > 0){
            int top = pq.poll();
            score += top;
            pq.add((int)(Math.ceil(top / 3.0)));
            k -= 1;
        }
        return score;
    }
}