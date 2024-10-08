class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i > -1; i--)
            if (i + nums[i] >= goal)
                goal = i;
        return goal == 0? true: false;
    }
};