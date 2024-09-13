#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int result = 0;
        for(int num: numsSet){
            if(numsSet.find(num - 1) == numsSet.end()){
                int length = 1;
                while(numsSet.find(num + length) != numsSet.end())length += 1;
                result = max(result, length);
            }
        }
        return result;
    }
};