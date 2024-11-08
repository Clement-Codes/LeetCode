class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xors = 0;
        for (int i: nums)
            xors ^= i;
        
        int maxi = (1 << maximumBit) - 1;

        vector<int> result;

        reverse(nums.begin(), nums.end());
        for (int i: nums){
            result.push_back(xors ^ maxi);
            xors ^= i;
        }

        return result;
    }
};