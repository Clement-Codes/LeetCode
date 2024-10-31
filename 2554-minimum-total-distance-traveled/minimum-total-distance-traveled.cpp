#define MAX 10000000000000LL
class Solution {
public:
    long long dfs(int i, int j, vector<int>& robot, vector<int>& factories, vector<vector<long>>& memo){
        if (i == -1) return 0;
        if (j == -1) return MAX;
        if (memo[i][j] != -1) return memo[i][j];
        long long include = abs(factories[j] - robot[i]) + dfs(i - 1, j - 1, robot, factories, memo);
        long long exclude = dfs(i, j - 1, robot, factories, memo);
        memo[i][j] = min(include, exclude);
        return memo[i][j];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;
        for (vector<int> temp: factory)
            for (int i = 0; i < temp[1]; i++)
                factories.push_back(temp[0]);
        vector<vector<long>> memo (robot.size(), vector<long>(factories.size(), -1));
        return dfs(robot.size() - 1, factories.size() - 1, robot, factories, memo);
    }
};