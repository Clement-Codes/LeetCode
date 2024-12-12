class Solution {
    public long pickGifts(int[] gifts, int k) {
        long result = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i: gifts)
            pq.add(i);
        while (k > 0){
            int x = pq.poll();
            pq.add((int)Math.floor(Math.sqrt(x)));
            k--;
        }
        while (pq.size() > 0){
            int temp = pq.poll();
            System.out.println(temp);
            result += temp;
            
        }

        return result;
    }
}