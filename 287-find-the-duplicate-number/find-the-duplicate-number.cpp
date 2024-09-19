#include<map>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int slow2 = 0;
        while (true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) return slow;
        }
        // map<int, int> results;
        // for(int i: nums){
        //     if(results.find(i)!=results.end()) return i;
        //     else results[i] = 1;
        // }
        // return -1;
    }
};