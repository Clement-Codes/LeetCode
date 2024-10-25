class Trie{
    HashMap<String, Trie> children = new HashMap<String, Trie>();
    boolean endOfWord = false;

    void add(String s){
        Trie curr = this;
        for (String ss: s.split("/")){
            if (!curr.children.containsKey(ss)){
                curr.children.put(ss, new Trie());
            }
            curr = curr.children.get(ss);
        }
        curr.endOfWord = true;
    }

    boolean prefix(String s){
        Trie curr = this;
        String[] splits = s.split("/");
        
        for (int i = 0; i < splits.length - 1; i++){
            curr = curr.children.get(splits[i]);
            if (curr.endOfWord) return true;
        }
        return false;
    }
}
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Trie cache = new Trie();
        List<String> result = new ArrayList<String>();
        for (String t: folder) cache.add(t);

        for (String t: folder){
            if (! cache.prefix(t)) result.add(t);
        }
        return result;
    }
    // public List<String> removeSubfolders(String[] folder) {
    //     List<String> result = new ArrayList<String>();
    //     HashSet<String> cache = new HashSet<String>();
    //     for (String i: folder) cache.add(i);
    //     for (String i: folder){
    //         result.add(i);
    //         for (int j = 0; j < i.length(); j++){
    //             if (i.charAt(j) == '/' && cache.contains(i.substring(0, j))){
    //                 result.remove(result.size() -1 );
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }
}