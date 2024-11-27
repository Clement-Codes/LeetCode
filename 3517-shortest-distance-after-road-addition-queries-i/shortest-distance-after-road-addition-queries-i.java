class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<List<Integer>> adj = new ArrayList<List<Integer>>();
        for (int i = 0; i < n - 1; i++)
        {
            adj.add(new ArrayList<Integer>());
            adj.get(i).add(i+1);
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++){
            adj.get(queries[i][0]).add(queries[i][1]);
            HashSet<Integer> visited = new HashSet<Integer>();
            Queue<Pair<Integer,Integer>> q = new LinkedList<Pair<Integer,Integer>>();
            q.add(new Pair<Integer,Integer>(0, 0));
            visited.add(0);
            while (q.size() > 0){
                Pair<Integer,Integer> temp = q.peek();
                q.remove();
                if (temp.getKey() == n - 1)
                {
                    result[i] = temp.getValue();
                    break;
                }
                for (int ii: adj.get(temp.getKey())){
                    if (!visited.contains(ii)){
                        q.add(new Pair<Integer,Integer>(ii, temp.getValue() + 1));
                        visited.add(ii);
                    }
                }
            }
        }
        return result;
    }
}