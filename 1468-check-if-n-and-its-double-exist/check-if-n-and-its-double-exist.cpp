class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> visited;

        for (int& i: arr){
            if (visited.contains(i * 2) || (i  % 2 == 0 && visited.contains(i / 2)))
                return true;
            visited.insert(i);
        }
        return false;
    }
};