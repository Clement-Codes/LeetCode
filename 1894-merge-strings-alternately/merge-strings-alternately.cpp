class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word ="";
        for(int i = 0; i < (word1.length() + word2.length()); i++){
            if(int(i/2) >= word1.length()){
                word = word + word2[i - word1.length()];
            }
            else if(int(i/2) >= word2.length()){
                word = word + word1[i - word2.length()];
            }
            else if(int(i/2) < word1.length() && int(i%2) == 0){
                word = word + word1[int(i/2)];
            }
            else if(int(i/2) < word2.length() && int(i%2) == 1){
                word = word + word2[int(i/2)];
            }
        }
        return word;
    }
};