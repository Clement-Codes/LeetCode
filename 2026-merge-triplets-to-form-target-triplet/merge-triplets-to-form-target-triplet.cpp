class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> result;
        for (vector<int> temp: triplets){
            if (temp[0] > target[0] || temp[1] > target[1] || temp[2] > target[2]) continue;
            for (int i = 0; i < 3; i++)
                if (temp[i] == target[i]) result.insert(i);
        }
        return result.size() == 3;
    }
};