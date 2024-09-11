#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> result = {};
        for(int i: nums){
            if (result.find(i) != result.end()) return true;
            result.insert(i);
        }   
        return false;
    }
};