#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> prev;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(prev.count(target - nums[i])){
                
                temp.push_back(prev[target - nums[i]]);
                temp.push_back(i);
                return temp;
            }
            else{
                prev[nums[i]] = i;
            }
        }
        return temp;
    }
};