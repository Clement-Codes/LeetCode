class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<double> nums2;
        int result = 0;
        for (int i: nums) nums2.insert(i);
        for (int i: nums2){
            if (nums2.contains(sqrt(i))) continue;
            int j = 1;
            int temp_i = i;
            while ( pow(i, 2) < 100000 and nums2.contains(i * i)){
                j += 1;
                i *= i;
            } 
            result = max(result, j);
        }
        return result > 1 ? result : -1;
    }
    // Sorting
    // int longestSquareStreak(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int result = 0;
    //     unordered_map<float, int> memo;
    //     for (int i: nums){
    //         memo[i] = memo[sqrt(i)] + 1;
    //         result = max(result, memo[i]);
    //     }
    //     return result > 1 ? result : -1; 
    // }
};