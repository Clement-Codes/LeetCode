class Solution {
    public int minCostConnectPoints(int[][] points) {
        HashMap<Integer, List<List<Integer>>> mapper = new HashMap<Integer, List<List<Integer>>>();
        for (int i = 0; i < points.length; i++){
            List<Integer> a = Arrays.asList(points[i][0], points[i][1]);
            for (int j = i; j < points.length; j++){
                List<Integer> b = Arrays.asList(points[j][0], points[j][1]);
                List<Integer> temp = Arrays.asList(Math.abs(a.get(0) - b.get(0)) + Math.abs(a.get(1) - b.get(1)), j);
                List<List<Integer>> t = mapper.getOrDefault(i, new ArrayList<List<Integer>>());
                t.add(temp);
                mapper.put(i, t); 
                temp = Arrays.asList(Math.abs(a.get(0) - b.get(0)) + Math.abs(a.get(1) - b.get(1)), i);
                t = mapper.getOrDefault(j, new ArrayList<List<Integer>>());
                t.add(temp);
                mapper.put(j, t);
            }
        }

        PriorityQueue<Pair<Integer,Integer>> q = new PriorityQueue<Pair<Integer,Integer>>(Comparator.comparingInt(a->a.getKey()));
        q.add(new Pair<Integer,Integer>(0,0));
        HashSet<Integer> visited = new HashSet<Integer>();
        int result = 0;
        while (visited.size() < points.length){
            Pair<Integer,Integer> temp = q.poll();
            if(visited.contains(temp.getValue())) continue;
            result += temp.getKey();
            visited.add(temp.getValue());
            for (List<Integer> t: mapper.get(temp.getValue()))
                if (!visited.contains(t.get(1))) q.add(new Pair<Integer,Integer>(t.get(0),t.get(1)));
        }
        return result;
    }
}