class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int prefix[] = new int[words.length + 1];
        Arrays.fill(prefix, 0);
        int result[] = new int[queries.length];
        Arrays.fill(result, 0);
        int prev = 0;
        HashSet<Character> vowels = new HashSet<Character>(){{add('a');add('e');add('i');add('o');add('u');}};

        for (int i = 0; i < words.length; i++){
            if (vowels.contains(words[i].charAt(0)) && vowels.contains(words[i].charAt(words[i].length() - 1))){
                prev += 1;
            }
            prefix[i + 1] = prev;
        }

        for (int i = 0; i < queries.length; i++){
            result[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return result;
    }
}