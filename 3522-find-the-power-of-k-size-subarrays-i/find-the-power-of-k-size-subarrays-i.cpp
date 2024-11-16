class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l = 0;
        int c = 1;
        vector<int> result;
        for (int r = 0; r < nums.size(); r++){
            if (r > 0 && nums[r - 1] + 1 == nums[r])
                c += 1;

            if (r - l + 1 > k){
                if (nums[l] + 1 == nums[l + 1])
                    c -= 1;
                l += 1;
            }
        
            if (r - l + 1 == k)
                result.push_back(c == k ? nums[r] : -1);
        }
        return result;
    }
};