import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        int maxArea = 0;
        Stack<Pair<Integer, Integer>> graph = new Stack<Pair<Integer, Integer>>();

        for(int i = 0; i < heights.length; i++){
            int start = i;
            while(!graph.empty() && heights[i] < graph.peek().getValue()){
                Pair<Integer, Integer> t = graph.peek();
                graph.pop();
                maxArea = Math.max(maxArea, t.getValue() * (i - t.getKey()));
                start = t.getKey();
            }
            Pair<Integer, Integer> temp  = new Pair<Integer, Integer>(start, heights[i]);
            graph.push(temp);
        }

        while(!graph.empty()){
            Pair<Integer, Integer> t = graph.peek();
            graph.pop();
            maxArea = Math.max(maxArea, t.getValue() * (heights.length - t.getKey()));
        }

        return maxArea;
    }
}