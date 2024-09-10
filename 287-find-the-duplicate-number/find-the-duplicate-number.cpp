#include<map>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> results;
        for(int i: nums){
            if(results.find(i)!=results.end()) return i;
            else results[i] = 1;
        }
        return -1;
    }
};