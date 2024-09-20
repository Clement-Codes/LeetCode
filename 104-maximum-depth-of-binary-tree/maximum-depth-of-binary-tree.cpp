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

#include<queue>
#include<stack>
class Solution {
public:
    // BFS recursive
    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;
    //     return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    // }

    // BFS iterative
    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int result = 0;
    //     while(q.size()){
    //         cout << q.size() <<": ";
    //         int len = q.size();
    //         for(int i = 0; i<len;i++){
    //             TreeNode* temp = q.front();
    //             cout << temp->val << ", " ;
    //             q.pop();
    //             if (temp->left){
    //                 q.push(temp->left);
    //             }
    //             if (temp->right){
    //                 q.push(temp->right);
    //             }
    //         }
    //         cout<<"\n";
    //         result += 1;
    //     }
    //     return result;
    // }

    // DFS iterative
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        pair<TreeNode*, int> head (root, 1);
        s.push(head);
        int result = 0;
        while (s.size()){
            pair<TreeNode*, int> temp = s.top();
            s.pop();
            if(temp.first){
                if(temp.first->left){
                    pair<TreeNode*, int> t (temp.first->left, 1 + temp.second);
                    s.push(t);
                }
                if(temp.first->right){
                    pair<TreeNode*, int> t (temp.first->right, 1 + temp.second);
                    s.push(t);
                }          
                result = max(result, temp.second);
            }
        }
        return result;
    }
};