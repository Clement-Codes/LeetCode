class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> memo;
        for (int i = 0; i < s.length(); i++){
            stringstream ss;
            for (int j = i; j < s.length(); j++){
                if (ss.str().length() == 0 || ss.str()[ss.str().length() - 1] == s[j])
                {
                    ss << s[j];
                    memo[ss.str()] = 1 + (memo.contains(ss.str()) ? memo[ss.str()] : 0);
                }
                else{
                    break;   
                }
            }
        }
        int result = 0;
        for(const auto& i: memo){
            if (i.second > 2 && result < i.first.length())
                result = i.first.length();
        }
        return result == 0 ? -1 : result;
    }
};