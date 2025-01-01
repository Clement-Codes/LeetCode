class Solution {
    public int maxScore(String s) {
        int zero = 0;
        int one = 0;
        for (char c: s.toCharArray())
            if (c == '1')
                one += 1;
        
        int result = 0;
        
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s.charAt(i) == '0')
            {
                zero += 1;
            }
            else{
                one -= 1;
            }
            result = Math.max(result, zero + one);
        }

        return result;
    }
}