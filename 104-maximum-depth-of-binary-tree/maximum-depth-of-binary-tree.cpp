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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(q.size()){
            cout << q.size() <<": ";
            int len = q.size();
            for(int i = 0; i<len;i++){
                TreeNode* temp = q.front();
                cout << temp->val << ", " ;
                q.pop();
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
            cout<<"\n";
            result += 1;
        }
        return result;
    }
};