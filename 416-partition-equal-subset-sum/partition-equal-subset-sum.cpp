class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i: nums)
            sum += i;
        int target = sum / 2;
        if ((sum % 2) == 1) return false;

        unordered_set<int> mapper;
        mapper.insert(0);

        for (int i = nums.size() - 1; i >= 0; i--){
            unordered_set<int> temp;
            for (int j: mapper){
                if (j + nums[i] == target) return true;
                temp.insert(j + nums[i]);
                temp.insert(j);
            }
            mapper = temp;
        }
        return false;
    }
};