class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        unordered_map<float, int> memo;
        for (int i: nums){
            memo[i] = memo[sqrt(i)] + 1;
            result = max(result, memo[i]);
        }
        return result > 1 ? result : -1; 
    }
};