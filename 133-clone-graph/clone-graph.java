/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Node, Node> oldToNew = new HashMap<Node, Node>();

    public Node dfs(Node node){
        if(oldToNew.containsKey(node)) return oldToNew.get(node);
        Node copy = new Node(node.val);
        oldToNew.put(node, copy);
        for(Node n : node.neighbors) copy.neighbors.add(dfs(n));
        return copy;
    }

    public Node cloneGraph(Node node) {
        return node!=null ? dfs(node) : null;
    }
}