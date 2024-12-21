class Solution {
    int result = 0;

    public long dfs(int curr, int parent, HashMap<Integer, List<Integer>> adj, int[] values, int k){
        long total = values[curr];

        for (int node: adj.getOrDefault(curr, new ArrayList<Integer>()))
            if (node != parent)
                total += dfs(node, curr, adj, values, k);

        if (total % k == 0){
            result += 1;
        }

        return total;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        HashMap<Integer, List<Integer>> adj = new HashMap<Integer, List<Integer>>();
        for (int[] edge: edges){
            List<Integer> temp = adj.getOrDefault(edge[0], new ArrayList<Integer>());
            temp.add(edge[1]);
            adj.put(edge[0], temp);
            temp = adj.getOrDefault(edge[1], new ArrayList<Integer>());
            temp.add(edge[0]);
            adj.put(edge[1], temp);
        }

        dfs(0, -1, adj, values, k);
        return result;
    
    }
}