class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> result;
        unordered_set<string> cache;
        for (string i: folder) cache.insert(i);
        for (string i: folder){
            result.push_back(i);
            for (int j = 0; j < i.length(); j++){
                if (i[j] == '/' && cache.contains(i.substr(0, j))){
                    result.pop_back();
                    break;
                }
            }
        }
        return result;
    }
};