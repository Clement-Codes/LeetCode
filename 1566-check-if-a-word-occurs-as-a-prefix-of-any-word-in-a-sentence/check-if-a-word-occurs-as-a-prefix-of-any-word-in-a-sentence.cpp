class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string temp = "";
        for (char i: sentence)
        {
            if (i == ' ')
            {
                words.push_back(temp);
                temp = "";
            }
            else{
                temp += i;
            }
                
        }
        words.push_back(temp);

        int l = 0;
        for (int i = 0; i < words.size(); i++){
            for(int j = 0; j < searchWord.length(); j++){
                if (words[i][j] != searchWord[j])
                    break;
                if (j == searchWord.length() - 1)
                    return i + 1;
            }
        }
        return -1;
    }
};