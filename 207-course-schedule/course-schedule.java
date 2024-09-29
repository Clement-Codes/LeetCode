import java.util.Vector;

class Solution {
    HashMap<Integer, Vector<Integer>> mapper = new HashMap<Integer, Vector<Integer>>();
    HashSet<Integer> visited = new HashSet<Integer>();

    boolean dfs(int i){
        if (visited.contains(i)) return false;
        if (mapper.getOrDefault(i, new Vector<Integer>()).size() == 0) return true;
        visited.add(i);
        for(int j: mapper.get(i))
            if (!dfs(j)) return false;
        visited.remove(i);
        mapper.get(i).removeAllElements();
        return true;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        for(int i[]: prerequisites){
            Vector<Integer> temp = mapper.getOrDefault(i[0], new Vector<Integer>());
            temp.add(i[1]);
            mapper.put(i[0], temp);
        }
            
        
        for(int i = 0; i < numCourses; i++)
            if (!dfs(i)) return false;

        return true;        
    }
}