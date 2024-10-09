class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> cache;
        for (int i = 0; i < s.length(); i++ ) cache[s[i]] = i;

        vector<int> result;
        int step = 0, end = 0;
        for (int i = 0; i < s.length(); i++ ){
            step += 1;
            end = max(end, cache[s[i]]);
            if(i == end){
                result.push_back(step);
                step = 0;
            }
        }
        return result;
    }
};