class Solution {
public:
    void updateBits(int* bits, int nums, int diff){
        for (int i = 0; i < 32; i++)
            if ((nums & (1 << i)) > 0)
                bits[i] += diff;
    }
    int getInteger(int* bits){
        int temp = 0;
        for (int i = 0; i < 32; i++)
            if (bits[i] > 0)
                temp+= (1 << i);
        return temp;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int bits[32] = {0};
        int l = 0;
        int result = INT_MAX;
        for (int r = 0; r < nums.size(); r++){
            updateBits(bits, nums[r], 1);
            int curr = getInteger(bits);
            while (curr >= k && l <= r){
                result = min(result, r - l + 1);
                updateBits(bits, nums[l], -1);
                curr = getInteger(bits);
                l += 1;
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};