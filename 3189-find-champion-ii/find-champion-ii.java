class Solution {
    public int findChampion(int n, int[][] edges) {
        int countParent[] = new int[n];
        Arrays.fill(countParent, 0);

        for (int[] edge: edges)
            countParent[edge[1]] += 1;
        
        List<Integer> champions = new ArrayList<Integer>();

        for (int i = 0; i < n; i++)
            if (countParent[i] == 0)
                champions.add(i);

        if (champions.size() > 1)
            return -1;
        return champions.get(0); 
    }
}