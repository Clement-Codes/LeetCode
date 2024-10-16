class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<Pair<Integer, Character>> pq = new PriorityQueue<Pair<Integer, Character>>((aa, bb) -> bb.getKey() - aa.getKey());
        String result = "";
        if (a > 0){
            pq.add(new Pair<Integer, Character>(a, 'a'));
        }
        if (b > 0){
            pq.add(new Pair<Integer, Character>(b, 'b'));
        } 
        if (c > 0){
            pq.add(new Pair<Integer, Character>(c, 'c'));
        }
        while (pq.size() > 0){
            Pair<Integer, Character> first = pq.poll();
            if(result.length() > 1 && result.charAt(result.length() - 1) == result.charAt(result.length() - 2) && result.charAt(result.length() - 1) == first.getValue()){
                if (pq.size() == 0) break;
                Pair<Integer, Character> second = pq.poll();
                result += second.getValue();
                if(second.getKey() - 1 > 0){
                    pq.add(new Pair<Integer, Character>(second.getKey() - 1, second.getValue()));
                }
            }
            else{
                result += first.getValue();
                first = new Pair<Integer, Character>(first.getKey() - 1, first.getValue());
            }
            if(first.getKey() > 0){
                pq.add(first);
            }
        }
        return result;
    }
}