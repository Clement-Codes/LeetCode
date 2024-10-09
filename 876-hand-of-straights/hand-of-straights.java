class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) return false;

        HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
        for (int i: hand)
            if (cache.containsKey(i)) cache.put(i, cache.get(i) + 1);
            else cache.put(i, 1);
        
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();
        for (Integer i: cache.keySet())
            q.add(i);

        while(q.size() > 0){
            int mini = q.peek();
            for (int i = mini; i < mini + groupSize; i++){
                if (!cache.containsKey(i)){
                    return false;
                }
                cache.put(i, cache.get(i) - 1);
                if (cache.get(i) == 0){
                    if (i != q.peek()){
                        return false;
                    }
                    q.remove();
                }
            }
        }
        return true;
    }
}