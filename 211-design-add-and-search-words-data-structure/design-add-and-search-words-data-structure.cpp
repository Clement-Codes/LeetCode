class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class WordDictionary {
public:
    TrieNode* root = new TrieNode();

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if (!curr->children.contains(c)) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool backtracking(int j, TrieNode* node, string word){
        TrieNode* curr = node;
        for(int i = j; i < word.length(); i++){
            if (word[i] == '.'){
                for (auto x: curr->children){
                    if (backtracking(i + 1, x.second, word)) return true;
                }
                return false;
            }
            else{
                if (!curr->children.contains(word[i])) return false;
                curr = curr->children[word[i]];
            }
        }
        return curr->endOfWord;
    }

    bool search(string word) {
        return backtracking(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */