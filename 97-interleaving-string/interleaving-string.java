class Solution {
    
    // HashMap<String, Boolean> cache = new HashMap<String, Boolean>();

    // public boolean dfs(int i, int j, String s1, String s2, String s3){
    //     if (i == s1.length() && j == s2.length()) return true;
    //     String key = String.valueOf(i) + "_" + String.valueOf(j);
    //     if (cache.containsKey(key)) return cache.get(key);
    //     if (i < s1.length() && s1.charAt(i) == s3.charAt(i + j) && dfs(i+1, j, s1, s2, s3)) return true;
    //     if (j < s2.length() && s2.charAt(j) == s3.charAt(i + j) && dfs(i, j+1, s1, s2, s3)) return true;
    //     cache.put(key,false);
    //     return cache.get(key);
    // } 


    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        // return dfs(0, 0, s1, s2, s3);
        boolean dp[][] = new boolean[s1.length() + 1][s2.length() + 1];
        dp[s1.length()][s2.length()] = true;
        for (int i = s1.length(); i >= 0; i--){
            for (int j = s2.length(); j >= 0; j--){
                if (i < s1.length() && s1.charAt(i) == s3.charAt(i + j) && dp[i + 1][j]) dp[i][j] = true;
                if (j < s2.length() && s2.charAt(j) == s3.charAt(i + j) && dp[i][j + 1]) dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
}