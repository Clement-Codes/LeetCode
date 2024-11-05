class Solution {
public:
    int minChanges(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i = i+2)
            if (s[i] != s[i+1])
                result += 1;
        return result;
    }
};