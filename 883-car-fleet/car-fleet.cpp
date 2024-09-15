#include<stack>
class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        return (a.first>b.first);
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> s;
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            pair<int,int> temp(position[i], speed[i]);
            cars.push_back(temp);
        }
        sort(cars.begin(), cars.end(), compare);
        for(auto i: cars){
            double steps = (target - i.first)/double(i.second);
            //s.push((target - i.first)/i.second);
            if(s.size()>0 && steps <= s.top()){
                continue;
            }
            else{
                s.push(steps);
            }
        }
        return s.size();
    }
};