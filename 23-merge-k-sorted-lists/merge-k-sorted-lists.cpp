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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        while(lists.size()>1){
            vector<ListNode*> mergedLists ;
            for(int i = 0; i < lists.size(); i = i+2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeSort(l1, l2)); 
            }
            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeSort(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1){
            tail->next = l1;
        }
        if (l2){
            tail->next = l2;
        }

        return dummy->next;
    }
};