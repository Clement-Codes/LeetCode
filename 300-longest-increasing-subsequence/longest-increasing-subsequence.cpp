class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int mapper [nums.size()];
        fill_n(mapper, nums.size(), 1);
        for (int i = nums.size() - 1; i >=0 ; i--)
            for (int j = i; j < nums.size(); j++)
                if (nums[i] < nums[j]) mapper[i] = max(mapper[i], 1 + mapper[j]);
            
        return * max_element(mapper, mapper + (sizeof(mapper) / sizeof(mapper[0])));
    }
};