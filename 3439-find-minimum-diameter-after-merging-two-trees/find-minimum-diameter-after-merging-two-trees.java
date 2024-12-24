class Solution {
    public HashMap<Integer, List<Integer>> getAdjacent (int[][] edges){
        HashMap<Integer, List<Integer>> adj = new HashMap<Integer, List<Integer>>();
        for (int[] i: edges){
            List<Integer> temp = adj.getOrDefault(i[0], new ArrayList());
            temp.add(i[1]);
            adj.put(i[0], temp);
            temp = adj.getOrDefault(i[1], new ArrayList());
            temp.add(i[0]);
            adj.put(i[1], temp);
        }
        return adj;
    }

    public int[] dfs(int curr, int parent, HashMap<Integer, List<Integer>> adj){
        int distance = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        pq.add(0);
        pq.add(0);
        for (int node: adj.getOrDefault(curr, new ArrayList<Integer>())){
            if (node == parent)
                continue;
            int[] temp = dfs(node, curr, adj);
            distance = Math.max(distance, temp[0]);
            pq.add(temp[1]);
            pq.poll();
        }
        int l = pq.poll();
        int r = pq.poll();
        distance = Math.max(distance, l + r);
        return new int[]{distance, 1 + (l > r ? l : r)};
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        HashMap<Integer, List<Integer>> adj1 = getAdjacent(edges1);
        HashMap<Integer, List<Integer>> adj2 = getAdjacent(edges2);

        int d1[] = dfs(0, -1, adj1);
        int d2[] = dfs(0, -1, adj2);

        return (int)Math.max(Math.max(d1[0], d2[0]), 1 + Math.ceil(d1[0] / 2.0) + Math.ceil(d2[0] / 2.0));
    }
}