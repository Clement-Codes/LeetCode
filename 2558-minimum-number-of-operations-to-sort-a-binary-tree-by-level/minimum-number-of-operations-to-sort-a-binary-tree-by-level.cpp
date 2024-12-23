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
    int countSwaps(vector<int>& nums){
        int result = 0;
        vector<int> sort_nums = nums;
        sort(sort_nums.begin(), sort_nums.end());
        unordered_map<int, int> idx_nums;
        for (int i = 0; i < nums.size(); i++)
            idx_nums[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sort_nums[i] != nums[i]){
                result++;
                int j = idx_nums[sort_nums[i]];
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                idx_nums[nums[j]] = j; 
            }
        }
        return result;
    }
    int minimumOperations(TreeNode* root) {
        deque<TreeNode*> d;
        d.push_back(root);
        int result = 0;
        while (d.size() > 0){
            int n = d.size();
            vector<int> nums;
            for (TreeNode* t: d)
                nums.push_back(t->val);
            while (n > 0){
                TreeNode* temp = d.front();
                d.pop_front();
                if (temp->left != nullptr)
                    d.push_back(temp->left);
                if (temp->right != nullptr)
                    d.push_back(temp->right);
                n--;
            }
            result += countSwaps(nums);
        }
        return result;
    }
};