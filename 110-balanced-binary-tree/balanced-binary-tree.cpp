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
    bool isBalanced(TreeNode* root) {
        return isBalancedDFS(root).first;
    }

    pair<bool, int> isBalancedDFS(TreeNode* root){
        if (! root){
            pair<bool,int> temp(true, 0);
            return temp;
        }

        pair<bool,int> left = isBalancedDFS(root->left);
        pair<bool,int> right = isBalancedDFS(root->right);
        bool balanced = abs(left.second - right.second) <= 1 && left.first && right.first ? true : false;
        pair<bool, int> result (balanced, 1 + max(left.second, right.second));
        return result;
    }
};