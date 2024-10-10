class Solution {
    public int sumOfSquares(int n){
        int output = 0;
        while (n > 0){
            output += Math.pow(n % 10, 2);
            n = n/10;
        }
        return output;
    }
    public boolean isHappy(int n) {
        HashSet<Integer> cache = new HashSet<Integer>();
        while (!cache.contains(n)){
            cache.add(n);
            n = sumOfSquares(n);
            if (n == 1) return true;
        }
        return false;
    }
}