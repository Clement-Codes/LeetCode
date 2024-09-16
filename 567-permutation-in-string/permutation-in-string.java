class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) return false;

            int m1[] = new int[26];
            int m2[] = new int[26];
            for(int i = 0; i < s1.length(); i++){
                m1[(int)(s1.charAt(i)) - (int)('a')] += 1;
                m2[(int)(s2.charAt(i)) - (int)('a')] += 1;
            }

            int match = 0;
            for(int i = 0; i < 26; i++){
                if (m1[i] == m2[i]) match += 1;
            }

            int l = 0;
            for(int i = s1.length(); i < s2.length(); i++){
                if (match == 26) return true;

                int index = (int)(s2.charAt(i)) - (int)('a');
                m2[index] += 1;
                if (m1[index] == m2[index]) match += 1;
                else if(m1[index] + 1 == m2[index]) match -= 1;

                index = (int)(s2.charAt(l)) - (int)('a');
                m2[index] -= 1;
                if (m1[index] == m2[index]) match += 1;
                else if(m1[index] - 1 == m2[index]) match -= 1;

                l += 1;

            }

            return match == 26;
    }
}