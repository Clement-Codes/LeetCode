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
        
        for (int i = 0; i < nums.size(); i++)
        {
            bool swap = false;
            for (int j = 0; j < nums.size() - i - 1; j++)
            {
                if (nums[j] < nums[j + 1]) continue;
                if (getBit(nums[j]) == getBit(nums[j + 1]))
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swap = true;
                }
                else{
                    return false;
                } 
            } 
            if (!swap) break;
        }
        return true;
    }
};