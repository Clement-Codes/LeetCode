class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int minv = 1, maxv = 1;
        for (int n: nums){
            int temp = maxv;
            maxv = max({maxv * n, minv * n, n});
            minv = min({temp * n, minv * n, n});
            result = max(result, maxv);
        }
        return result;
    }
};