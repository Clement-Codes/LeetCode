class Solution {
public:
    int dfs(int i, unordered_set<string> cache, string s){
        if (i == s.length()) return 0;
        int result = 0;
        for (int j = i + 1; j <= s.length(); j++){
            string substring = s.substr(i, j - i);
            if (cache.contains(substring)) continue;

            cache.insert(substring);
            result = max(result, 1 + dfs(j, cache, s));
            cache.erase(substring);
        }
        return result;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> cache;
        return dfs(0, cache, s);
    }
};