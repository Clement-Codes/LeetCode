class Solution {
    public String mergeAlternately(String word1, String word2) {
        String word = "";
        for(int i = 0; i < (word1.length() + word2.length()); i++){
            if((int)(i/2) >= word1.length()){
                word = word.concat(String.valueOf(word2.charAt(i - word1.length())));
            }
            else if((int)(i/2) >= word2.length()){
                word = word.concat(String.valueOf(word1.charAt(i - word2.length())));
            }
            else if((int)(i/2) < word1.length() && (int)(i%2) == 0){
               word = word.concat(String.valueOf(word1.charAt((int)(i/2))));
            }
            else if((int)(i/2) < word2.length() && (int)(i%2) == 1){
                word = word.concat(String.valueOf(word2.charAt((int)(i/2))));
            }
        }
        return word;
    }
}