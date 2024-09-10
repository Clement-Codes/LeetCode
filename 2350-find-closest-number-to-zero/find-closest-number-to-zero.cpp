class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int minIndex = 0;
        for(int i = 0; i<nums.size(); i++){
            if (abs(nums.at(i)) < abs(nums.at(minIndex))){
                minIndex = i;
            }
            else if (abs(nums.at(i)) == abs(nums.at(minIndex)) && nums.at(i) > nums.at(minIndex)){
                minIndex = i;
            }
        }
        return nums.at(minIndex);
    }
};