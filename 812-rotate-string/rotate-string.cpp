class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s + s;
        return s.length() == goal.length() && t.find(goal) != string::npos;
    }
};