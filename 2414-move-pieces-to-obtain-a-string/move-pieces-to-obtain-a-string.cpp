class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        while (i < start.length() || j < target.length()){
            cout << i << " " << j <<"\n";
            while (start[i] == '_')
                i++;
            while (target[j] == '_')
                j++;
            if (i == start.length() || j == target.length())
                return i == start.length() && j == target.length();
            if (start[i] != target[j] || start[i] == 'L' && i < j || start[i] == 'R' && i > j)
                return false;
            i++;
            j++;             
        }
        return true;
    }
};