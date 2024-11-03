class Solution {
    public boolean isCircularSentence(String sentence) {
        int i = 0;
        while (i < sentence.length()){
            if (sentence.charAt(i) == ' ' && sentence.charAt(i - 1) != sentence.charAt(i + 1)) return false;
            i++;
        }
        return sentence.charAt(0) == sentence.charAt(sentence.length() - 1);
    }
}