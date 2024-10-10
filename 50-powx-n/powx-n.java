class Solution {
    public double helper(double x, long n){
        if (x == 0) return 0;
        if (n == 0) return 1;
        double res = helper(x, n/2);
        res = res*res;
        return n % 2 == 1 ? x * res: res;
    }
    public double myPow(double x, int n) {
        double result = helper(x , Math.abs((long) n));
        return n >= 0 ? result : 1/result;
    }
}