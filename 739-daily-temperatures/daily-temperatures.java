import java.util.Stack;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int result[] = new int[temperatures.length];
        Stack<Integer> s = new Stack<Integer>();
        Stack<Integer> si = new Stack<Integer>();
        for(int i = 0; i < temperatures.length; i++) result[i] = 0;

        for(int i = 0; i < temperatures.length; i++){
            while(!s.empty() && temperatures[i]>s.peek()){
                result[si.peek()] = i - si.peek();
                s.pop();
                si.pop();
            }
            s.push(temperatures[i]);
            si.push(i);
        }
        return result;
    }
}