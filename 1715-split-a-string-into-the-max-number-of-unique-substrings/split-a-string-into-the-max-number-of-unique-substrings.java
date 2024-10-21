class Solution {
    int dfs(int i, HashSet<String> cache, String s){
        if (i == s.length()) return 0;
        int result = 0;
        for (int j = i + 1; j <= s.length(); j++){
            String substring = s.substring(i, j);
            if (cache.contains(substring)) continue;
            cache.add(substring);
            result = Math.max(result, 1 + dfs(j, cache, s));
            cache.remove(substring);
        }
        return result;
    }

    public int maxUniqueSplit(String s) {
        HashSet<String> cache = new HashSet<String>();
        return dfs(0, cache, s);        
    }
}