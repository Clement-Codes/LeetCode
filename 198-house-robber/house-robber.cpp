class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int n: nums){
            int temp = max(rob1+n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return max(rob1, rob2);
    }
};