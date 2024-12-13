class Solution {
    public long findScore(int[] nums) {
        long result = 0;
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>((p,q) -> Integer.compare(p.getKey() * 10 + p.getValue(), q.getKey() * 10 + q.getValue()));
        for (int i = nums.length - 1; i >=0; i--)
        {
            Pair<Integer, Integer> temp = new Pair<Integer, Integer>(nums[i], i);
            pq.add(temp);
        }
        boolean visited[] = new boolean[nums.length];
        Arrays.fill(visited, false);
        while(pq.size() > 0){
            Pair<Integer, Integer> temp = pq.poll();            
            if (!visited[temp.getValue()])
            {
            result += temp.getKey();
            visited[temp.getValue()] = true;
            if (temp.getValue() > 0)
                visited[temp.getValue() - 1] = true;
            if (temp.getValue() < nums.length -1)
                visited[temp.getValue()  + 1] = true;
            }
            
        }
        return result;
    }
}