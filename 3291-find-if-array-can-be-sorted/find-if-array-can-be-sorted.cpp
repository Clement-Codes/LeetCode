class Solution {
public:
    int getBit(int n){
        int result = 0;
        while (n > 0){
            result += n & 1;
            n = n >> 1;
        }
        return result;
    }

    bool canSortArray(vector<int>& nums) {
        int min_curr = nums[0], max_curr = nums[0], prev_curr = INT_MIN;
        for (int n: nums){
            if (getBit(n) == getBit(min_curr)){
                min_curr = min(min_curr, n);
                max_curr = max(max_curr, n);
            }
            else{
                if (min_curr < prev_curr) return false;
                prev_curr = max_curr;
                min_curr = n;
                max_curr = n;
            }
        }
        return min_curr < prev_curr ? false : true;
    }
    // O(N2) Bubble Sort
    // bool canSortArray(vector<int>& nums) {
        
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         bool swap = false;
    //         for (int j = 0; j < nums.size() - i - 1; j++)
    //         {
    //             if (nums[j] < nums[j + 1]) continue;
    //             if (getBit(nums[j]) == getBit(nums[j + 1]))
    //             {
    //                 int temp = nums[j];
    //                 nums[j] = nums[j + 1];
    //                 nums[j + 1] = temp;
    //                 swap = true;
    //             }
    //             else{
    //                 return false;
    //             } 
    //         } 
    //         if (!swap) break;
    //     }
    //     return true;
    // }
};