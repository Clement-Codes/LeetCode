class Solution {
public:
    string makeFancyString(string s) {
        int streak = 1;
        string result = "";
        for (int i = 0; i < s.length(); i++){
            if (i > 0 && s[i] == s[i-1]) streak += 1;
            else streak = 1;
            if (streak < 3) result += s[i];
        }
        return result;
    }
};