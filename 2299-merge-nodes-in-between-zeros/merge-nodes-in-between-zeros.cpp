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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* result = new ListNode();
        ListNode* itterator = head->next;
        ListNode* resultItterator = result;
        int val = 0;

        while (itterator != nullptr){
            if (itterator->val == 0){
                resultItterator->val = val;
                if (itterator->next != nullptr){
                    ListNode* temp = new ListNode();
                    resultItterator->next = temp;
                    resultItterator = resultItterator->next;
                }
                val = 0;
            }
            else{
                val += itterator->val;
            }
            itterator = itterator->next;
        }
        return result;
    }
};