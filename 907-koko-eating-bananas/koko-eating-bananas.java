class Solution {

    public int getMax(int piles[]){
        int result = 0;
        for(int i: piles)
            if(i > result) result = i;
        return result;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int l = 1;
        int r = getMax(piles);
        int result = r;

        while (l <= r) {
            long m = l + ((r - l) / 2);
            long th = 0;

            for (double pile : piles)
                th += Math.ceil(pile / m);

            if (th <= h) {
                result = (int)(m);
                r = (int)m - 1;
            } else
                l = (int)m + 1;
        }

        return result;
    }
}