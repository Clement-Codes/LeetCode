class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX;
        int neg_count = 0;
        for(vector<int> r: matrix)
            for(int c: r)
            {
                sum += abs(c);
                mini = min(mini, abs(c));
                if (c < 0)
                    neg_count++;
            }
        return neg_count % 2 == 0 ? sum : sum - (mini * 2); 
    }
};