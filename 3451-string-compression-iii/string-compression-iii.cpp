class Solution {
public:
    string compressedString(string word) {
        char curr = word[0];
        int consec = 1;
        string result = "";
        for(int i = 1; i < word.size(); i++){
            if (curr == word[i] && consec < 9) consec += 1;
            else{
                result += to_string(consec) + curr;
                curr = word[i];
                consec = 1;
            }
        }
        result += to_string(consec) + curr;
        return result;
    }
};