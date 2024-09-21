/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<stack>
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int n = 0;
        stack<TreeNode*> s;
        while (curr != nullptr or s.size() > 0){
            while (curr != nullptr){
                s.push(curr);
                curr = curr->left;
            }
            TreeNode* temp  =  s.top();
            s.pop();
            n += 1;
            if (n == k){
                return temp->val;
            }
            curr = temp->right;
        }
        return -1;
    }
};