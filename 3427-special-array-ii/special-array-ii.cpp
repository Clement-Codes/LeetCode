class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> result(queries.size(), false);
        vector<int> prefix(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            prefix[i + 1] = prefix[i];
            if (nums[i] % 2 == nums[i + 1] % 2)
            prefix[i + 1] += 1;
        }
        for (int i = 0; i < queries.size(); i++)
            result[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == 0;
        return result;
    }
};