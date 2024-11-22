class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        HashMap<String, Integer> cache = new HashMap<String, Integer>();
        int result = Integer.MIN_VALUE;
        for (int i[]: matrix){
            String key = "";
            StringBuilder s = new StringBuilder();
            for (int j: i){
                if (i[0] == 1){
                    s.append((j == 1 )? 0: 1);
                }
                else{
                    s.append(j);
                }
            }
            key = s.toString();
            if (cache.containsKey(key))
                cache.put(key, cache.get(key) + 1);
            else
                cache.put(key, 1);
            result = Math.max(result, cache.get(key));
        }
        return result;
    }
}