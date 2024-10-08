class Solution {
public:
    unordered_map<string, bool> cache;

    bool dfs(int i, int j, string& s, string& p){
        
        string key = to_string(i) + "_" + to_string(j);
        if (cache.contains(key)) return cache[key];

        if (i >= s.length() && j >= p.length()) return true;
        if (j >= p.length()) return false;

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j+1] == '*'){
            cache[key] = dfs(i, j+2, s, p) || (match && dfs(i+1, j, s, p));
            return cache[key];
        }

        if (match){
            cache[key] = dfs(i + 1, j + 1, s, p);
            return cache[key];
        }

        cache[key] = false;
        return cache[key];
    }

    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};