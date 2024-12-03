class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ss;
        string result;
        int i = 0, j = 0;
        while (i < s.length() && j < spaces.size()){
            if (i < spaces[j]){
                ss << s[i];
                i++;
            }
            else{
                ss << " ";
                j++;
            }
        }
        while (i < s.length()){
            ss << s[i];
            i++;
        }
        result = ss.str();
        return result;
    }
};