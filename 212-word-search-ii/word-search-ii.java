public class TrieNode{
    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    int ref = 0;
    boolean endOfWord = false;

    public void add(String word){
        TrieNode curr = this;
        curr.ref++;
        for(Character c: word.toCharArray()){
            if(!curr.children.containsKey(c)) curr.children.put(c, new TrieNode());
            curr = curr.children.get(c);
            curr.ref++;
        }
        curr.endOfWord = true;
    }

    public void remove(String word){
        TrieNode curr = this;
        curr.ref--;
        for(char c: word.toCharArray()){
            if(curr.children.containsKey(c)){
                curr = curr.children.get(c);
                curr.ref--;
            } 
        }
        curr.endOfWord = false;
    }
};



class Solution {
    int ROW;
    int COL;
    
    void backtracking(int i, int j, String word, TrieNode node, char[][] board, HashSet<String> result, HashSet<String> visited, TrieNode root){
        if(i<0 || j<0 || i==ROW || j==COL || !node.children.containsKey(board[i][j]) || node.children.get(board[i][j]).ref < 1 || visited.contains(String.valueOf(i) + ',' + String.valueOf(j))) return;

        node = node.children.get(board[i][j]);
        word = word + board[i][j];
        visited.add(String.valueOf(i) + ',' + String.valueOf(j));
        if(node.endOfWord){
            result.add(word);
            root.remove(word);
        }
        backtracking(i + 1, j, word, node, board, result, visited, root);
        backtracking(i - 1, j, word, node, board, result, visited, root);
        backtracking(i, j + 1, word, node, board, result, visited, root);
        backtracking(i, j - 1, word, node, board, result, visited, root);
        visited.remove(String.valueOf(i) + ',' + String.valueOf(j));
    }
    public List<String> findWords(char[][] board, String[] words) {
                TrieNode root = new TrieNode();
        for(String word: words) root.add(word);

        HashSet<String> result = new HashSet<String>();
        HashSet<String> visited = new HashSet<String>();
        ROW = board.length;
        COL = board[0].length;

        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                backtracking(i, j, "", root, board, result, visited, root);
        
        List<String> t = new ArrayList<String>(result);
        return t;
    }
}