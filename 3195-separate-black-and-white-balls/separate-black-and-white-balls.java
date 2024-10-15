class Solution {
    public long minimumSteps(String s) {
        long swaps = 0;
        long black = 0;
        for (char c: s.toCharArray()){
            if (c == '1'){
                black += 1;
            }
            else{
                swaps += black;
            }
        }
        return swaps;
        // long white = 0;
        // for (int i = 0; i < s.length(); i++){
        //     if (s.charAt(i) == '0'){
        //         swaps += i - white;
        //         white += 1;
        //     }
        // }
        // return swaps;
    }
}