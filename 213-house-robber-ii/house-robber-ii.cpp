class Solution {
public:
    int helper(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int n: nums){
            int temp = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }

    int rob(vector<int>& nums) {
        vector<int> a = {nums.begin(), nums.end()-1};
        vector<int> b = {nums.begin() + 1, nums.end()};
        return max({nums[0], helper(a), helper(b)});
    }
};