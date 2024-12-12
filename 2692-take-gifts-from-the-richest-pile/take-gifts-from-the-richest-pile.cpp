class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;
        priority_queue<int> pq;
        for(int i: gifts)
            pq.push(i);
        while (k > 0){
            int x = pq.top();
            pq.pop();
            pq.push(floor(sqrt(x)));
            k--;
        }
        while (pq.size() > 0)
        {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};