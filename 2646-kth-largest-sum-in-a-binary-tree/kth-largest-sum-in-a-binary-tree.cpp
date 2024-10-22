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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);
        while(q.size() > 0){
            int l = q.size();
            long long s = 0;
            while (l > 0){
                TreeNode* temp = q.front();
                q.pop();
                s += temp->val;
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
                l -= 1;
            }
            pq.push(s);
            if (pq.size() > k){
                pq.pop();
            }
        }

        return pq.size() < k ? -1 : pq.top();
    }
};