class Solution {
public:
//    unordered_map<string, bool> cache;

    // bool dfs(int i, int j, string s1, string s2, string s3){
    //     if (i == s1.length() && j == s2.length()) return true;
    //     string key = to_string(i) + "_" + to_string(j);
    //     if (cache.contains(key)) return cache[key];
    //     if (i < s1.length() && s1[i] == s3[i+j] && dfs(i+1, j, s1, s2, s3)) return true;
    //     if (j < s2.length() && s2[j] == s3[i+j] && dfs(i, j+1, s1, s2, s3)) return true;
    //     cache[key] = false;
    //     return cache[key];
    // } 

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        // return dfs(0, 0, s1, s2, s3);
        bool** dp = new bool*[s1.length() + 1];
        for (int i = 0; i < s1.length() + 1; i++){
            dp[i] = new bool[s2.length() + 1]();
        }
        dp[s1.length()][s2.length()] = true;
        for (int i = s1.length(); i >= 0; i--){
            for (int j = s2.length(); j >= 0; j--){
                if (i < s1.length() && s1[i] == s3[i+j] && dp[i + 1][j]) dp[i][j] = true;
                if (j < s2.length() && s2[j] == s3[i+j] && dp[i][j + 1]) dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};