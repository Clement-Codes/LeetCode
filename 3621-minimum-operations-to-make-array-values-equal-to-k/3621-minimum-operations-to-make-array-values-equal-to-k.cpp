class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for (int i : nums){
            if (i < k){
                return -1;
            }
            else if (i > k){
                st.insert(i);
            }
        }
        return st.size();
    }
};