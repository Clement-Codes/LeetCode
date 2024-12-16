class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>((p,q) -> {
            int valueCompare = Integer.compare(p.getKey(), q.getKey());
            if (valueCompare == 0)
                return Integer.compare(p.getValue(), q.getValue());
            return valueCompare;
            });
        for (int i = 0; i < nums.length; i++)
            pq.add(new Pair<Integer, Integer>(nums[i], i));

        while (k > 0){
            Pair<Integer, Integer> temp = pq.poll();
            nums[temp.getValue()] *= multiplier;
            pq.add(new Pair<Integer, Integer>(nums[temp.getValue()], temp.getValue()));
            k -= 1;
        }
        return nums;
    }
}