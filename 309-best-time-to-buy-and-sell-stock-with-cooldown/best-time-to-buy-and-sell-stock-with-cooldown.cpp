class Solution {
public:
    unordered_map<string, int> mapper;  

    int dfs(int i, bool task, vector<int>& prices){
        if (i >= prices.size()) return 0;
        string key = to_string(i) + "_" + (task ? "t":"f");
        if (mapper.contains(key)) return mapper[key];
        if (task){
            int buying = dfs(i+1, !task, prices) - prices[i];
            int cooldown = dfs(i+1, task, prices);
            mapper[key] = max(buying, cooldown);
        }
        else{
            int selling = dfs(i+2, !task, prices) + prices[i];
            int cooldown = dfs(i+1, task, prices);
            mapper[key] = max(selling, cooldown);
        }
        return mapper[key];
    }

    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }
};