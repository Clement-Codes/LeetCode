class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
        PriorityQueue<List<Integer>> pq = new PriorityQueue<List<Integer>>((p,q) -> q.get(0) - p.get(0));

        for (char c: s.toCharArray())
            cache.put((int) c, 1 + cache.getOrDefault((int) c, 0));
        
        for (Map.Entry<Integer, Integer> temp: cache.entrySet())
            pq.add(new ArrayList(Arrays.asList(temp.getKey(), temp.getValue())));

        StringBuilder ss = new StringBuilder();
        while (pq.size() > 0){
            List<Integer> curr = pq.poll();
            for(int i = 0; i < Math.min(curr.get(1), repeatLimit); i++)
                ss.append((char)curr.get(0).intValue());
            if (curr.get(1) - repeatLimit  > 0 && pq.size() > 0){
                List<Integer> next = pq.poll();
                ss.append((char)next.get(0).intValue());
                if (next.get(1) > 1)
                    pq.add(new ArrayList(Arrays.asList(next.get(0), next.get(1) - 1)));
                pq.add(new ArrayList(Arrays.asList(curr.get(0), curr.get(1) - repeatLimit)));
            }
            
        }
        return ss.toString();
    }
}