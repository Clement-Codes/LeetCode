#include<unordered_map>

class Node{
    public:
    Node* prev = nullptr;
    Node* next = nullptr;
    int key;
    int value;

    public:
    Node(int key1, int value1){
        key = key1;
        value = value1;
    }
};

class LRUCache {
    int capacity;
    Node* left = new Node(0, 0);
    Node* right = new Node(0, 0);

    unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity1) {
        capacity = capacity1;
        left->next = right;
        right->prev = left;
    }
    
    void add(Node* temp){
        Node* tempLeft = right->prev;
        tempLeft->next = temp;
        temp->prev = tempLeft;
        temp->next = right;
        right->prev = temp;
    }

    void remove(Node* temp){
        Node* tempLeft = temp->prev;
        Node* tempRight = temp->next;
        tempLeft->next = tempRight;
        tempRight->prev = tempLeft;
    }

    int get(int key) {
        if(cache.contains(key)){
            remove(cache[key]);
            add(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
            remove(cache[key]);
            cache.erase(key);
        }
        Node* temp = new Node(key, value);
        cache[key] = temp;
        add(cache[key]);

        if(cache.size() > capacity){
            
            cache.erase(left->next->key);
            remove(left->next);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */