class Solution {
public:
    struct values{
        int location;
        int lenght;
        string bb;
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> moves = { {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}}
        };
        stringstream ss;
        for (vector<int> r: board)
            for (int c: r)
                ss << to_string(c);
        string b;
        ss >> b;
        queue<values> q;
        int t = b.find('0');
        q.push({t, 0, b.c_str()});
        string final = "123450";
        unordered_set<string> visited;
        visited.insert(b);
        while(q.size() > 0){
            values temp = q.front();
            q.pop();
            if (temp.bb == final)
                return temp.lenght;
            for (int i: moves[temp.location]){
                string temp2 = temp.bb.c_str();
                char tt = temp2[i];
                temp2[i] = temp2[temp.location];
                temp2[temp.location] = tt;
                if (!visited.contains(temp2)){
                    visited.insert(temp2);
                    q.push({i, temp.lenght + 1, temp2.c_str()});
                }
            }
        }
        return -1;
    }
};