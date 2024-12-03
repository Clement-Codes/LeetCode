class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ss;
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
        // while (i < s.length()){
        //     ss << s[i];
        //     i++;
        // }
        ss << s.substr(i, s.length());
        return ss.str();
    }
};