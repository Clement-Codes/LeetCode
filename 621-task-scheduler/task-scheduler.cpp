#include<unordered_map>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hm;
        for(char i: tasks){
            if(hm.contains(i)){
                hm[i] += 1;
            }else hm[i] = 1;
        }
        priority_queue<int> pq;
        for(pair<char, int> i: hm)
            pq.push(i.second);
        queue<pair<int, int>> history;
        int time = 0;
        while (pq.size() > 0 || history.size() > 0){
            time += 1;
            if (pq.size() > 0){
                int temp = pq.top() - 1;
                pq.pop();
                if (temp > 0){
                    pair<int, int> h (temp, time + n);
                    history.push(h);
                }
            }
            if (history.size()>0 && history.front().second == time){
                int temp = history.front().first;
                history.pop();
                pq.push(temp);
            }
        }
        return time;
    }
};