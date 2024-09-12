#include<map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> results;
        for(string s: strs){
            vector<int> count;
            for(int i = 0; i < 26; i++){
                count.push_back(0);
            }
            for(char c: s){
                count[int(c) - int('a')] += 1;
            }
            results[count].push_back(s);
        }
        for(const auto i : results){
            result.push_back(i.second);
        }
        return result;
    }
};