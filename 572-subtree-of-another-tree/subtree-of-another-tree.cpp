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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if (isSameTree(root, subRoot)) return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool isSameTree(TreeNode* n1, TreeNode* n2){
        if (n1 == nullptr && n2 == nullptr) return true;
        if ((n1 != nullptr && n2 == nullptr) || (n1 == nullptr && n2 != nullptr) || (n1->val != n2->val)) return false;
        return isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);
    }
};