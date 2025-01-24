class Solution {
    Boolean dfs(int i, int[][] graph, HashMap<Integer, Boolean> safe){
        if (safe.containsKey(i))
            return safe.get(i);
        safe.put(i,false);
        for (int j: graph[i])
            if (!dfs(j, graph, safe))
                return safe.get(i);
        safe.put(i,true);
        return safe.get(i);
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<Integer> result = new ArrayList<Integer>();
        HashMap<Integer, Boolean> safe = new HashMap<Integer, Boolean>();

        for (int i = 0; i < n; i++)
            if (dfs(i, graph, safe))
                result.add(i);
        return result;
    }
}