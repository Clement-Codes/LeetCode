class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
    TrieNode(){
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    Trie() {
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word){
            if (!curr->children.contains(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word){
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix){
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */