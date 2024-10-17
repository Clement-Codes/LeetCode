class Solution {
    public int maximumSwap(int num) {
        String temp = String.valueOf(num);
        char max_v = '0';
        int max_i = temp.length() - 1, i = temp.length() - 1, j = temp.length() - 1;
        for (int ii = temp.length() - 1; ii >= 0; ii--){
            if (max_v < temp.charAt(ii)){
                max_v = temp.charAt(ii);
                max_i = ii;
            }
            if (max_v > temp.charAt(ii)){
                i = ii;
                j = max_i;
            }
        }
        char [] tt = temp.toCharArray();
        char t = tt[i];
        tt[i] = tt[j];
        tt[j] = t;
        temp = String.valueOf(tt);
        return Integer.valueOf(temp);
    }
}