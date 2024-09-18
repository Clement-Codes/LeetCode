class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + ((r-l)/2);
            if (target == nums[m]) return m;

            if (nums[l] <= nums[m]){
                if (target>nums[m] or target < nums[l]) l += 1;
                else r -= 1;
            }
            else{
                if (target < nums[m] or target > nums[r]) r -= 1;
                else l +=1;

            }
        }
        return -1;
    }
};