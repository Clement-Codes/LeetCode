class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (p, q) -> Integer.compare(p[0], q[0]));
        PriorityQueue<List<Integer>> pq = new PriorityQueue<List<Integer>>((p,q) -> Integer.compare(p.get(0), q.get(0)));
        int maxSum = 0;
        int maxCarry = 0;
        for (int[] event: events){
            while(pq.size() > 0 && pq.peek().get(0) < event[0]){
                maxCarry = Math.max(maxCarry, pq.poll().get(1));
            }
            maxSum = Math.max(maxSum, maxCarry + event[2]);
            pq.add(new ArrayList(Arrays.asList(event[1], event[2])));
        }
        return maxSum;
    }
}