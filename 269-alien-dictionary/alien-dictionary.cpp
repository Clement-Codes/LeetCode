class Solution {
public:
    unordered_map<char, vector<char>> mapper;
    unordered_map<char, bool> visited;
    vector<char> result;

    bool dfs(char i){
        if(visited.contains(i)) return visited[i];

        visited[i] = true;

        for(char j: mapper[i]){
            if (dfs(j)) return true;
        }

        visited[i] = false;
        result.push_back(i);
        return false;
    }

    string alienOrder(vector<string>& words) {
        
        for (string word: words){
            for (char l: word){
                mapper[l] = vector<char>();
            }
        }
        for (int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i + 1];
            int mini = min(word1.length(), word2.length());
            if (word1.length() > word2.length() && word1.substr(0, mini) == word2.substr(0, mini)){
                return "";
            }
            for (int j = 0; j < mini; j++){
                if(word1[j] != word2[j]){
                    mapper[word1[j]].push_back(word2[j]);
                    break;
                }
            }
        }
        
        for (pair<char, vector<char>> temp: mapper){
            if (dfs(temp.first)){
                return "";
            }
        }

        reverse(result.begin(), result.end());
        return string(result.begin(), result.end());
    }
};