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
    int result = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        result = max(result, left + right);
        return max(1 + left, 1 + right);
    }
};