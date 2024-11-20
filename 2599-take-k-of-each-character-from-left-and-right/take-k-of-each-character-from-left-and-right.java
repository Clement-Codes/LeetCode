class Solution {
    public int takeCharacters(String s, int k) {
        int count[] = {0, 0, 0};

        for (char c: s.toCharArray())
            count[c - 'a'] += 1;

        if (Arrays.stream(count).min().getAsInt() < k) return -1;

        int l = 0;
        int result = Integer.MAX_VALUE;
        int n = s.length();
        for (int r = 0; r < n; r++){
            count[s.charAt(r) - 'a'] -= 1;

            if (Arrays.stream(count).min().getAsInt() < k){
                count[s.charAt(l) - 'a'] += 1;
                l += 1;
            }

            result = Math.min(result, n - (r - l + 1));
        }
        return result;
    }
}