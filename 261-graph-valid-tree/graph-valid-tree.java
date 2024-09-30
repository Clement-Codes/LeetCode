import java.util.Vector;

class Solution {
    public boolean dfs(int i, int prev, HashSet<Integer> visited, HashMap<Integer, Vector<Integer>> mapper){
        if (visited.contains(i)) return false;
        visited.add(i);
        for(int j: mapper.getOrDefault(i, new Vector<Integer>())){
            if (j == prev) continue;
            else if (! dfs(j, i, visited, mapper)) return false;
        }
        return true;
    }

    public boolean validTree(int n, int[][] edges) {
        HashMap<Integer, Vector<Integer>> mapper = new HashMap<Integer, Vector<Integer>> ();
        for(int[] t: edges){
            Vector<Integer> temp = mapper.getOrDefault(t[0], new Vector<Integer>());
            temp.add(t[1]);
            mapper.put(t[0], temp);
            temp = mapper.getOrDefault(t[1], new Vector<Integer>());
            temp.add(t[0]);
            mapper.put(t[1], temp);
        }

        HashSet<Integer> visited = new HashSet<Integer>();

        return dfs(0, -1, visited, mapper) && n == visited.size();
    }
}