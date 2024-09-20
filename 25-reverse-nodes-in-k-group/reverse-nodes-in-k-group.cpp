/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tail = dummy;
        
        while (true){
            ListNode* Kth = getKthNode(tail, k);
            if (!Kth) break;

            ListNode* nextGroup = Kth->next;
            ListNode* curr = tail->next;
            ListNode* prev = Kth->next;

            while(curr != nextGroup){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = tail->next;
            tail->next = prev;
            tail = temp;
        }

        return dummy->next;
    }

    ListNode* getKthNode(ListNode* Node, int k){
        while(Node && k){
            Node = Node->next;
            k -= 1;
        }
        return Node;
    }
};