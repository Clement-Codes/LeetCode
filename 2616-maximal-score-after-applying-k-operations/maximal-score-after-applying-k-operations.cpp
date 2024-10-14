class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq;
        for (int i: nums)
            pq.push(i);
        while(k > 0){
            int top = pq.top();
            pq.pop();
            score += top;
            pq.push(ceil(top / 3.0));
            k -= 1;
        }
        return score;
    }
};