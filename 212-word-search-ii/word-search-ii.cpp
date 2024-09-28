class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    int ref = 0;
    bool endOfWord = false;

    void add(string word){
        TrieNode* curr = this;
        curr->ref++;
        for(char c: word){
            if(!curr->children.contains(c)) curr->children[c] = new TrieNode();
            curr = curr->children[c];
            curr->ref++;
        }
        curr->endOfWord = true;
    }

    void remove(string word){
        TrieNode* curr = this;
        curr->ref--;
        for(char c: word){
            if(curr->children.contains(c)){
                curr = curr->children[c];
                curr->ref--;
            } 
        }
        curr->endOfWord = false;
    }
};

class Solution {

public:
    int ROW;
    int COL;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word: words) root->add(word);

        unordered_set<string> result;
        unordered_set<string> visited;
        ROW = board.size();
        COL = board[0].size();

        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                backtracking(i, j, "", root, board, result, visited, root);

        return vector<string>(result.begin(), result.end());
    }

private:
    void backtracking(int i, int j, string word, TrieNode* node, vector<vector<char>>& board, unordered_set<string>& result, unordered_set<string>& visited, TrieNode* root){
        if(i<0 || j<0 || i==ROW || j==COL || !node->children.contains(board[i][j]) || node->children[board[i][j]]->ref < 1 || visited.contains(to_string(i) + ',' + to_string(j))) return;

        node = node->children[board[i][j]];
        word = word + board[i][j];
        visited.insert(to_string(i) + ',' + to_string(j));
        if(node->endOfWord){
            result.insert(word);
            root->remove(word);
        }
        backtracking(i + 1, j, word, node, board, result, visited, root);
        backtracking(i - 1, j, word, node, board, result, visited, root);
        backtracking(i, j + 1, word, node, board, result, visited, root);
        backtracking(i, j - 1, word, node, board, result, visited, root);
        visited.erase(to_string(i) + ',' + to_string(j));
    }
};