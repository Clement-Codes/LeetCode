class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        unordered_map<string, vector<string>> mapper;
        wordList.push_back(beginWord);

        for (string word: wordList){
            for (int i = 0; i < word.length(); i++){
                mapper[word.substr(0, i) + "*" + word.substr(i + 1, word.length() - (i + 1))].push_back(word);
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int result = 1;

        while(q.size()>0){
            int l = q.size();

            for(int i = 0; i < l; i++){
                string temp = q.front();
                q.pop();

                if (temp == endWord) return result;
                for (int j = 0; j < temp.length(); j++){
                    for (string t: mapper[temp.substr(0, j) + "*" + temp.substr(j + 1, temp.length() - (j + 1))]){
                        if (!visited.contains(t)){
                                q.push(t);
                                visited.insert(t);
                        }
                    }
                }
            }

            result += 1;
        }
        return 0;
    }
};