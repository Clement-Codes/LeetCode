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
    int goodNodes(TreeNode* root) {
        return dfsGoodNodes(root, root->val);
    }

    int dfsGoodNodes(TreeNode* node, int maxValue){
        if (node == nullptr) return 0;
        int result = node->val >= maxValue ? 1: 0;
        maxValue = max(node->val, maxValue);
        result += dfsGoodNodes(node->left, maxValue) + dfsGoodNodes(node->right, maxValue);
        return result;
    }
};