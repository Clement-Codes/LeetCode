class Solution {
    public int[][] validArrangement(int[][] pairs) {
        HashMap<Integer, List<Integer>> adjMatrix = new HashMap<>();
        HashMap<Integer, Integer> inDegree = new HashMap<>();
        HashMap<Integer, Integer> outDegree = new HashMap<>();
        int[][] pairResult = new int[pairs.length][2];
        List<Integer> result = new ArrayList<Integer>();
        for (int pair[]: pairs){
            if (adjMatrix.containsKey(pair[0]))
                adjMatrix.get(pair[0]).add(pair[1]);
            else
                adjMatrix.put(pair[0], new ArrayList<Integer>(Arrays.asList(pair[1])));
        
            if (inDegree.containsKey(pair[1]))
                inDegree.put(pair[1], inDegree.get(pair[1]) + 1);
            else
                inDegree.put(pair[1], 1);

            if (outDegree.containsKey(pair[0]))
                outDegree.put(pair[0], outDegree.get(pair[0]) + 1);
            else
                outDegree.put(pair[0], 1);
        }

        int startNode = -1;

        for (int i: outDegree.keySet())
            if (outDegree.get(i) == inDegree.getOrDefault(i, 0) + 1){
                startNode = i;
                break;
            }

        if (startNode == - 1)
            startNode = pairs[0][0];
        
        Deque<Integer> d = new LinkedList<Integer>();
        d.push(startNode);

        while (d.size() > 0){
            int node = d.peekLast();
            if (adjMatrix.getOrDefault(node, new ArrayList<Integer>()).size() > 0){
                d.addLast(adjMatrix.get(node).get(0));
                adjMatrix.get(node).remove(adjMatrix.get(node).get(0));
            }
            else{
                result.add(node);
                d.removeLast();
            }
        }

        //result = result.reversed();
        Collections.reverse(result);
        for (int i = 1; i < result.size(); i++){
            pairResult[i - 1][0] = result.get(i-1);
            pairResult[i - 1][1] = result.get(i);
        }

        return pairResult;
    }
}