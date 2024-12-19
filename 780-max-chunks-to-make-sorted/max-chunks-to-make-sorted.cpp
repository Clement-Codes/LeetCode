class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = -1;
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            m = max(m, arr[i]);
            if (i == m)
                result++;
        }
        return result;
    }
};