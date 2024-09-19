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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 or l2 or carry){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int add = val1 + val2 + carry;
            int val = add % 10;
            carry = floor(add/10.0);

            ListNode* temp = new ListNode(val);
            curr->next = temp;
            curr = curr->next;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

        }

        return dummy->next;
    }
};