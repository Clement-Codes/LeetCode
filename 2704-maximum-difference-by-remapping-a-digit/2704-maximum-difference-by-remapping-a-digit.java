class Solution {
    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        String maxi = s;
        for (char c: s.toCharArray()){
            if(c != '9'){
                maxi = maxi.replaceAll(String.valueOf(c), "9");
                break;
            }
        }
        String mini = s.replaceAll(String.valueOf(s.charAt(0)), "0");
        return Integer.valueOf(maxi) - Integer.valueOf(mini);
    }
}