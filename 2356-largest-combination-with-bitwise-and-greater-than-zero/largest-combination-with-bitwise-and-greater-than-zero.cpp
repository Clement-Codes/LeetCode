class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);
        for (int n: candidates){
            int i = 0;
            while (n > 0){
                count[i] += n & 1;
                n = n >> 1;
                i += 1;
            }
        }
        int result = 0;
        for (int n: count)
            if (result < n) result = n;
        return result;
    }
};