class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> countParent(n, 0);

        for (vector<int> edge: edges)
            countParent[edge[1]] += 1;
        
        vector<int> champions;

        for (int i = 0; i < n; i++)
            if (countParent[i] == 0)
                champions.push_back(i);

        if (champions.size() > 1)
            return -1;
        return champions[0];
    }
};