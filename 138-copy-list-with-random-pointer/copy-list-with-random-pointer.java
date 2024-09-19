/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
import java.util.HashMap;

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node,Node> old = new HashMap<Node, Node>();
        old.put(null, null);
        
        Node cur = head;
        while(cur != null){
            Node copy = new Node(cur.val);
            old.put(cur, copy);
            cur = cur.next;
        }
        
        cur = head;
        while(cur != null){
            Node copy = old.get(cur);
            copy.next = old.get(cur.next);
            copy.random = old.get(cur.random);
            old.put(cur, copy);
            cur = cur.next;
        }

        return old.get(head);
    }
}