class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] mapper = new int[text1.length() + 1][text2.length() + 1];
        for (int[] temp: mapper)
            Arrays.fill(temp, 0);
        for (int i = text1.length() - 1; i >=0 ; i--)
            for (int j = text2.length() - 1; j >=0 ; j--)
                if(text1.charAt(i) == text2.charAt(j)){
                    mapper[i][j] = 1 + mapper[i+1][j+1];
                }
                else{
                    mapper[i][j] = Math.max(mapper[i+1][j], mapper[i][j+1]);
                }
        return mapper[0][0];
    }
}