import java.util.HashMap;

class Node{
    Node prev = null;
    Node next = null;
    int key;
    int value;

    Node(int key, int value){
        this.key = key;
        this.value = value;
    }
};

class LRUCache {
    int capacity;
    Node left = new Node(0, 0);
    Node right = new Node(0, 0);
    HashMap<Integer, Node> cache = new HashMap<Integer, Node>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        left.next = right;
        right.prev = left;
    }

    public void add(Node temp){
        Node tempLeft = right.prev;
        tempLeft.next = temp;
        temp.prev = tempLeft;
        temp.next = right;
        right.prev = temp;
    }

    public void remove(Node temp){
        Node tempLeft = temp.prev;
        Node tempRight = temp.next;
        tempLeft.next = tempRight;
        tempRight.prev = tempLeft;
    }

    public int get(int key) {
        if(cache.containsKey(key)){
            remove(cache.get(key));
            add(cache.get(key));
            return cache.get(key).value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key)){
            remove(cache.get(key));
            cache.remove(key);
        }
        Node temp = new Node(key, value);
        cache.put(key, temp);
        add(cache.get(key));

        if(cache.size() > capacity){
            cache.remove(left.next.key);
            remove(left.next);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */