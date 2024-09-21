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
    int result;
public:
    int maxPathSum(TreeNode* root) {
        result = root->val;
        pathSum(root);
        return result;
    }

    int pathSum(TreeNode* node){
        if (node == nullptr) return 0;

        int left = pathSum(node->left);
        int right = pathSum(node->right);
        int leftMax = max(left, 0);
        int rightMax = max(right, 0);

        result = max(result, node->val + leftMax + rightMax);
        return node->val + max(leftMax, rightMax);
    }
};