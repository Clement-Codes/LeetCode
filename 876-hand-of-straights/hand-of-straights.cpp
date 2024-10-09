class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> cache;
        for (int i: hand)
            if (cache.contains(i)) cache[i] += 1;
            else cache[i] = 1;
        
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto i: cache)
            q.push(i.first);

        while(q.size() > 0){
            int mini = q.top();
            for (int i = mini; i < mini + groupSize; i++){
                if (!cache.contains(i)){
                    cout << 1;
                    return false;
                }
                cache[i] -= 1;
                if (cache[i] == 0){
                    if (i != q.top()){
                        return false;
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};