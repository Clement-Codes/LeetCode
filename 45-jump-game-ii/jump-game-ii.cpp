class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int l = 0, r = 0;
        while (r < nums.size() - 1){
            int largest = 0;
            for (int i = l; i < r + 1; i++){
                largest = max(largest, i + nums[i]);
            }
            l = r + 1;
            r = largest;
            result += 1;
        }
        return result;
    }
};