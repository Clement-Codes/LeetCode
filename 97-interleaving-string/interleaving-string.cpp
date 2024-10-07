class Solution {
public:
    unordered_map<string, bool> cache;

    bool dfs(int i, int j, string s1, string s2, string s3){
        if (i == s1.length() && j == s2.length()) return true;
        string key = to_string(i) + "_" + to_string(j);
        if (cache.contains(key)) return cache[key];
        if (i < s1.length() && s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3)) return true;
        if (j < s2.length() && s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3)) return true;
        cache[key] = false;
        return cache[key];
    } 

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        return dfs(0, 0, s1, s2, s3);
    }
};