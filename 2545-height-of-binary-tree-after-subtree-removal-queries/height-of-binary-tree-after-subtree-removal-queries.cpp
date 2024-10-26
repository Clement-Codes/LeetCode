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
    int preprocessing(TreeNode* curr, int level, unordered_map<int, int>& levels, unordered_map<int, int>& heights, unordered_map<int, pair<int,int>>& maxheights){
        if (curr == nullptr) return 0;
        int height = 1 + max(preprocessing(curr->left, level + 1, levels, heights, maxheights), preprocessing(curr->right, level + 1, levels, heights, maxheights));
        levels[curr->val] = level;
        heights[curr->val] = height;
        if (height > maxheights[level].first){
            maxheights[level].second = maxheights[level].first;
            maxheights[level].first = height;
        }
        else if (height > maxheights[level].second){
            maxheights[level].second = height;
        }
        return height;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> levels, heights;
        vector<int> result;
        unordered_map<int, pair<int,int>> maxheights;
        preprocessing(root, 0, levels, heights, maxheights);
        for (int i: queries){
            int temp_level = levels[i];
            int temp_height = heights[i];
            result.push_back((temp_height == maxheights[temp_level].first ? maxheights[temp_level].second : maxheights[temp_level].first) + temp_level - 1);
        }

        return result;
    }
};