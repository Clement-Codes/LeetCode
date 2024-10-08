class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        for(int i: nums){
            if (sum < 0) sum = 0;
            sum += i;
            result = max(result, sum);
        }
        return result;
    }
};