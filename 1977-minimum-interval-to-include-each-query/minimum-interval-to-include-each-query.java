class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals, Comparator.comparingDouble(a -> a[0]));
        int tempQueries[] = queries.clone();
        Arrays.sort(tempQueries);
        PriorityQueue<Pair<Integer, Integer>> q = new PriorityQueue<Pair<Integer, Integer>>(Comparator.comparing(Pair::getKey));
        int result[] = new int[queries.length];
        HashMap<Integer, Integer> cache = new HashMap<Integer, Integer>();
        int l = 0;
        for (int i: tempQueries){
            while (l < intervals.length && intervals[l][0] <= i){
                q.add(new Pair<Integer, Integer>(intervals[l][1] - intervals[l][0] + 1, intervals[l][1]));
                l += 1;
            }
            while (q.size() > 0 && q.peek().getValue() < i) q.remove();

            cache.put(i, q.size()>0 ? q.peek().getKey() : -1);
        }
        for (int i = 0; i < queries.length; i++){
            result[i] = cache.get(queries[i]);
        }
        return result; 
    }
}