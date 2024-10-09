class Solution {
    public List<Integer> partitionLabels(String s) {
        HashMap<Character, Integer> cache = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++ ) cache.put(s.charAt(i), i);

        List<Integer> result = new ArrayList<Integer>();
        int step = 0, end = 0;
        for (int i = 0; i < s.length(); i++ ){
            step += 1;
            end = Math.max(end, cache.get(s.charAt(i)));
            if(i == end){
                result.add(step);
                step = 0;
            }
        }
        return result;
    }
}