class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> tt = {{}};
        if (nums.size() == 0) return tt;
        vector<int> temp = {nums.begin() + 1, nums.end()};
        vector<vector<int>> permutation = permute(temp);
        vector<vector<int>> result;
        for(vector<int> i: permutation){
            for(int j = 0; j < i.size() + 1; j ++){
                vector<int> t = i;
                t.insert(t.begin() + j, nums[0]);
                result.push_back(t);
            }
        }
        return result;
    }
};