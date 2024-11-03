class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i = 0;
        while (i < sentence.length()){
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) return false;
            i++;
        }
        return sentence[0] == sentence[sentence.length() - 1];
    }
};