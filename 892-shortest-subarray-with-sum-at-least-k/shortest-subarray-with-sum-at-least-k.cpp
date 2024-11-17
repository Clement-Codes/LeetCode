class Solution {
public:
    static bool compare(pair<long, int> a, pair<long, int>b){
        return a.first > b.first;
    }
    int shortestSubarray(vector<int>& nums, int k) {
        //Using Heap
        long s = 0;
        int result = INT_MAX;
        priority_queue<pair<long, int>, vector<pair<long, int>>, function<bool(pair<long, int>, pair<long, int>)>> pq(compare);
        for (int r = 0; r < nums.size(); r++){
            s += nums[r];
            if (s >= k) result = min(result, r + 1);
            
            while (pq.size() > 0  && s - pq.top().first >= k){
                pair<long, int> temp = pq.top();
                pq.pop();
                result = min(result, r - temp.second);
            }

            pq.push(pair<long, int>{s, r});
        }
        return result == INT_MAX ? -1 : result;
    }
};