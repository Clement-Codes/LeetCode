class Solution {
public:
    int getMax(vector<int>& piles) {
        int result = 0;
        for (int i : piles)
            if (i > result)
                result = i;
        return result;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = getMax(piles);
        int result = r;

        while (l <= r) {
            double m = l + ((r - l) / 2);
            long th = 0;

            for (double pile : piles)
                th += ceil(pile / m);

            if (th <= h) {
                result = m;
                r = m - 1;
            } else
                l = m + 1;
        }

        return result;
    }
};