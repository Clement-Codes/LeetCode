class Solution {
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);

        HashMap<Integer, List<List<Integer>>> grouped = new HashMap<Integer, List<List<Integer>>>();
        for (int i = 0; i < queries.length; i++){
            int l = queries[i][0], r = queries[i][1];
            if (l > r){
                int temp = l;
                l = r;
                r = temp;
            }
            if (l == r || heights[l] < heights[r]){
                result[i] = r;
            }
            else{
                List<List<Integer>> temp = grouped.getOrDefault(r, new ArrayList<List<Integer>>());
                temp.add(Arrays.asList(heights[l], i));
                grouped.put(r, temp);
            }
        }

        PriorityQueue<List<Integer>> pq = new PriorityQueue<List<Integer>>((p, q) -> Integer.compare(p.get(0),q.get(0)));

        for (int i = 0 ;i < heights.length; i++){
            for (List<Integer> j: grouped.getOrDefault(i, new ArrayList<List<Integer>>())){
                pq.add(j);
            }

            while (pq.size() > 0 && heights[i] > pq.peek().get(0)){
                List<Integer> temp = pq.poll();
                result[temp.get(1)] = i;
            }
        }
        return result;
    }
}