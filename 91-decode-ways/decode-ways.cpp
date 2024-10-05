class Solution {
public:
    unordered_map<int, int> mapper;
    int dfs(int i, string s){
        if (mapper.contains(i)) return mapper[i];
        if (s[i] == '0') return 0;
        int result = dfs(i + 1, s);
        if (i + 1 < s.size() && (s[i] == '1' or (s[i] == '2' and (s[i + 1] >= '0' and s[i+1] <= '6'))))
            result += dfs(i + 2, s);
        mapper[i] = result;
        return result;
    }

    int numDecodings(string s) {
        mapper[s.size()] = 1;
        return dfs(0, s);
    }
};