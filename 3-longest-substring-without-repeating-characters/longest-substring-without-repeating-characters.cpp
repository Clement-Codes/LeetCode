#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sets;
        int result = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            while(sets.contains(s[r])){
                sets.erase(sets.find(s[l]));
                l += 1;
            }
            sets.insert(s[r]);
            result = max(result, r - l + 1);
        }
        return result;
    }
};