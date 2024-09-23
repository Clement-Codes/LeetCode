class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i: nums) q.push(i);
        int n = 1;
        while(n < k){
            q.pop();
            n += 1;
        }
        return q.top();
    }
};