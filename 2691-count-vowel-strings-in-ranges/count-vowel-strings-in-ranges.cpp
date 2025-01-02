class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        vector<int> result(queries.size(), 0);
        int prev = 0;
        unordered_set<char> vowels = {'a','e','i','o','u'};

        for (int i = 0; i < words.size(); i++){
            if (vowels.contains(words[i][0]) && vowels.contains(words[i][words[i].length() - 1])){
                prev += 1;
            }
            prefix[i + 1] = prev;
        }

        for (int i = 0; i < queries.size(); i++){
            result[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }

        return result;
    }
};