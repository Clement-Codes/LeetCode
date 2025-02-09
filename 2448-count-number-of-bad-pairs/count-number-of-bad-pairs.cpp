class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        long long goodPairs = 0;
        long long totalPairs = 0;
        for (int i = 0; i < nums.size(); i++){
            totalPairs += i;
            int index = nums[i] - i;
            goodPairs += count.contains(index) ? count[index] : 0;
            if (count.contains(index))
                count[index] += 1;
            else
                count[index] = 1;
        }

        return totalPairs - goodPairs;
    }
};