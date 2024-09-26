class Solution {
public:
    void backtracking(int index,string curr, vector<string>& result, string digits, unordered_map<char, vector<char>> numberToLetter){
        cout<<curr<<"\n";
        if(curr.length() == digits.length()){
            result.push_back(curr);
            return;
        }
        for (char i:  numberToLetter[digits[index]])
            backtracking(index + 1, curr + i, result, digits, numberToLetter);

    }

            

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> numberToLetter = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
        vector<string> result;
        if (digits.length() > 0)
            backtracking(0,"", result, digits, numberToLetter);
        return result;
    }
};