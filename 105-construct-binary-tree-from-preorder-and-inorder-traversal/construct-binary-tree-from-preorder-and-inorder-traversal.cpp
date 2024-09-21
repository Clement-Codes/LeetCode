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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 or inorder.size() == 0) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);

        int midIndex = int(find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin());
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + midIndex + 1);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + midIndex);
        root->left = buildTree(left_preorder, left_inorder);

        vector<int> right_preorder(preorder.begin() + midIndex + 1, preorder.end());
        vector<int> right_inorder(inorder.begin() + midIndex + 1, inorder.end());
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};