class Solution {
    public int shortestSubarray(int[] nums, int k) {
       Deque<Pair<Long, Integer>> d = new ArrayDeque<>();
       long s = 0;
       int result = Integer.MAX_VALUE;
       for (int r = 0; r < nums.length; r++){
            s += nums[r];
            if (s >= k) result = Math.min(result, r + 1);

            while (d.size() > 0 && s - d.getFirst().getKey() >= k){
                Pair<Long, Integer> temp = d.getFirst();
                d.removeFirst();
                result = Math.min(result, r - temp.getValue());
            }

            while (d.size() > 0 && d.getLast().getKey() >= s)
                d.removeLast();

            d.addLast(new Pair<Long, Integer>(s, r));
       }
       return result == Integer.MAX_VALUE ? -1 : result;
    

        //Using Heap
        // long s = 0;
        // int result = Integer.MAX_VALUE;
        // PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        // for (int r = 0; r < nums.length; r++){
        //     s += nums[r];
        //     if (s >= k) result = Math.min(result, r + 1);
            
        //     while (pq.size() > 0  && s - pq.peek().getKey() >= k){
        //         Pair<Long, Integer> temp = pq.poll();
        //         result = Math.min(result, r - temp.getValue());
        //     }

        //     pq.add(new Pair<Long, Integer>(s, r));
        // }
        // return result == Integer.MAX_VALUE ? -1 : result;
    }
}