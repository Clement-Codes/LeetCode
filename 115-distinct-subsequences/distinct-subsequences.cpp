class Solution {
public:
    unordered_map<string, int> cache;
    int dfs(int i, int j, string& s, string& t){
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        string key = to_string(i) + "_" + to_string(j);
        if (cache.contains(key)) return cache[key];

        if (s[i] == t[j]) cache[key] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        else cache[key] = dfs(i + 1, j, s, t);

        return cache[key];
    }

    int numDistinct(string s, string t) {
        return dfs(0, 0, s, t);
    }
};