class Solution {
public:
    bool helper(vector<int>& nums, int maxOperations, int ball){
        int o = 0;
        for (int i: nums){
            o += (ceil(i / (ball * 1.0)) - 1);
            if (o > maxOperations)
            {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        while (l < r){
            int m = l + (r - l) / 2;
            if (helper(nums, maxOperations, m)){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return r;
    }
};