class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool* mapper = new bool[s.size() + 1];
        fill_n(mapper,s.size() + 1, false);
        mapper[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--){
            for (string word: wordDict){
                if (i+word.size() <= s.size() && s.substr(i, word.size()) == word)
                    mapper[i] = mapper[i+word.size()];
                if (mapper[i]) break;
            }
        }
    
        return mapper[0];
    }
};