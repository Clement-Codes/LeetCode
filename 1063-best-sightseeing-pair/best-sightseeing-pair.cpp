class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        int m = 0;
        for (int i: values){
            result = max(result, m + i);
            m = max(m - 1, i - 1);
        }
        return result;
    }
};