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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            vector<int> temp;
            int l = q.size();
            for (int i = 0; i < l; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node != nullptr){
                    temp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(temp.size()>0){
                result.push_back(temp);
            }
        }
        return result;
    }
};