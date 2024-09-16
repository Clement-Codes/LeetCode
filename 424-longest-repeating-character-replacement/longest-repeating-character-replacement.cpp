#include<unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int l = 0;
        int result = 0;
        int mmax = 0;
        for(int r = 0; r < s.length(); r++){
            if(m.contains(s[r])){
                m[s[r]] += 1;
            }
            else{
                m[s[r]] = 1;
            }
            mmax = max(mmax, m[s[r]]);
            if((r-l+1) - mmax > k){
                m[s[l]] -= 1;
                l += 1;
            }
            result = max(result, (r-l+1));
        }
        return result;
    }
};