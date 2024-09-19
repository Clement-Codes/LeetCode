/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include<unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> old;
        old[nullptr] = nullptr;
        
        Node* cur = head;
        while(cur){
            Node* copy = new Node(cur->val);
            old[cur] = copy;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            old[cur]->next = old[cur->next];
            old[cur]->random = old[cur->random];
            cur = cur->next;
        }

        return old[head];
    }
};