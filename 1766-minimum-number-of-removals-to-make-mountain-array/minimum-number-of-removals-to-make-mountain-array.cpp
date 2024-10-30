class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        for (int i = 0; i < n ; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    pre[i] = max(pre[i], 1 + pre[j]);

        vector<int> pos(n, 1);
        for (int i = n - 1; i >= 0 ; i--)
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j])
                    pos[i] = max(pos[i], 1 + pos[j]);
        
        int result = n;
        for (int i = 0; i < n; i++)
            if (min(pos[i], pre[i]) != 1)
                result = min(result, n - pos[i] - pre[i] + 1);
                
        return result;
    }
};