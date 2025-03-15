class Solution {
public:
    int is_valid(int capacity, vector<int>& nums, int k){
        int i = 0;
        int count = 0;
        while (i < nums.size()){
            if (nums[i] <= capacity){
                i += 2;
                count += 1;
            }
            else{
                i += 1;
            }
            if (count == k)
                break;
        }
        return count == k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());
        int result = 0;
        while (l <= r){
            int m = (l + r) / 2;
            if (is_valid(m, nums, k)){
                result = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return result;
    }
};