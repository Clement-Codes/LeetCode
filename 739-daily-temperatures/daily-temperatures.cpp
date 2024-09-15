#include<stack>
#include<array>

#include<unordered_set>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        stack<int> s;
        stack<int> si;
        for(int i: temperatures) result.push_back(0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[i] > s.top()){
                result[si.top()] = i - si.top();
                s.pop();
                si.pop();
            }
            s.push(temperatures[i]);
            si.push(i);
        }
        return result;
    }
};