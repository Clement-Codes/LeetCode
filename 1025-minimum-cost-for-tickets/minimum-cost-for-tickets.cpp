class Solution {
public:
    int noOfDays[3] = {1, 7, 30};
    unordered_map <int, int> memo;
    
    int dfs(int index, vector<int>& days, vector<int>& costs){

        if (memo.contains(index))
            return memo[index];
            
        memo[index] = INT_MAX;

        for (int i = 0; i < 3; i++){
            int j = index;
            while (j < days.size() && days[j] < days[index] +  noOfDays[i])
                j += 1;
            memo[index] = min(memo[index] , costs[i] + dfs(j, days, costs));
        }
        return memo[index] ;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo[days.size()] = 0;
        return dfs(0, days, costs);
    }
};