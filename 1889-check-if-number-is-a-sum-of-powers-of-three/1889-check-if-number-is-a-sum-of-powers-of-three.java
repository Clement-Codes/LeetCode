class Solution {
    public boolean backtracking(int c, int i, int n){
        if (c == n) return true;
        else if ((c > n) || (Math.pow(3, i) > n)) return false;

        if (backtracking(c + (int)Math.pow(3, i), i + 1, n)) return true;

        return backtracking(c, i + 1, n);
    }

    public boolean checkPowersOfThree(int n) {
        // return backtracking(0, 0, n);
        int i = 0;
        while (Math.pow(3, i + 1) <= n)
            i += 1;
        while (i >= 0){
            int current = (int)Math.pow(3, i);
            if (current <= n)
                n -= current;
            if (current <= n)
                return false;
            i-=1;
        }
        return n == 0;
    }
}