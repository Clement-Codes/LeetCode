#include<stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> graph;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!graph.empty() && heights[i] < graph.top().second){
                auto t = graph.top();
                graph.pop();
                maxArea = max(maxArea, (i-t.first) * t.second );
                start = t.first;
            }
            pair<int,int>temp(start, heights[i]);
            graph.push(temp);
        }
        while(!graph.empty()){
            auto t = graph.top();
            graph.pop();
            int h = heights.size();
            maxArea = max(maxArea,  (h - t.first) * t.second );
        }
        return maxArea;
    }
};