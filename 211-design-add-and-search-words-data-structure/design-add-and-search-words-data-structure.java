class TrieNode{
    HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
    boolean endOfWord = false;

    TrieNode(){

    }
}
class WordDictionary {
    TrieNode root = new TrieNode();

    public WordDictionary() {
        
    }
    
    public void addWord(String word) {
        TrieNode curr = root;
        for(Character c: word.toCharArray()){
            if (!curr.children.containsKey(c)) curr.children.put(c, new TrieNode());
            curr = curr.children.get(c);
        }
        curr.endOfWord = true;
    }
    
    public boolean backtracking(int j, TrieNode node, String word){
        TrieNode curr = node;
        for (int i = j; i < word.length(); i++){
            if(word.charAt(i) == '.'){
                for(Map.Entry<Character, TrieNode> temp: curr.children.entrySet()){
                    if (backtracking(i+1, temp.getValue(), word)) return true;
                }
                return false;
            }
            else{
                if(!curr.children.containsKey(word.charAt(i))) return false;
                curr = curr.children.get(word.charAt(i));
            }
        }
        return curr.endOfWord;
    }

    public boolean search(String word) {
        return backtracking(0, root, word);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */