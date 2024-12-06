class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b (banned.begin(), banned.end());
        int count = 0;
        for (int i = 1; i < n + 1; i++){
            if (b.contains(i))
                continue;
            maxSum -= i;
            if (maxSum < 0)
                return count;
            count += 1;
        }
        return count;
    }
};