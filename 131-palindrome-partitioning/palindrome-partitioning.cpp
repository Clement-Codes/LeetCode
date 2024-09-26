class Solution {
public:
    bool palidrome(string s, int l, int r){
        while (l < r){
            if (s[l] != s[r]) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }

    void partition(int i, string s, vector<string>& path, vector<vector<string>>& result){
        if (i >= s.length()){
            result.push_back(path);
            return;
        }
        for(int j = i; j < s.length(); j++){
            if (palidrome(s, i, j)){
                path.push_back(s.substr(i, j-i + 1));
                partition(j + 1, s, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition(0, s, path, result);
        return result;
    }
};