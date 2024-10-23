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
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        
        while (q.size() > 0){
            int length = q.size();
            int sum = 0;
            while (length > 0){
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
                sum += temp->val;
                length -= 1;
            }
            level.push_back(sum);
        }

        queue<pair<TreeNode*, int>> q2;
        q2.push(pair<TreeNode*, int> (root, root->val));
        int curr = 0;
        while (q2.size() > 0){
            int length = q2.size();
            while (length > 0){
                pair<TreeNode*, int> temp = q2.front();
                temp.first->val = level[curr] - temp.second;
                q2.pop();
                int sibling = 0;
                if (temp.first->left != nullptr) sibling += temp.first->left->val;
                if (temp.first->right != nullptr) sibling += temp.first->right->val;
                if (temp.first->left != nullptr) q2.push(pair<TreeNode*, int> (temp.first->left, sibling));
                if (temp.first->right != nullptr) q2.push(pair<TreeNode*, int> (temp.first->right, sibling));
                length -= 1;
            }
            curr += 1;
        }


        return root;
    }
};