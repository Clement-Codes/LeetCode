import java.util.ArrayList;
import java.util.Stack;

class Solution {
    public void backTracking(int o, int c, int n, Stack<Character> s, List<String> r){
        if(o == c && c == n){
            Stack<Character> temp = new Stack<Character>();
            temp.addAll(s);
            String temp1 = "";
            while(!temp.empty()){
                temp1 = temp.peek() + temp1;
                temp.pop();
            }
            r.add(temp1);
        }
        if(o<n){
            s.push('(');
            backTracking(o + 1, c, n, s, r);
            s.pop();
        }
        if(c<o){
            s.push(')');
            backTracking(o, c + 1, n, s, r);
            s.pop();
        }
    }

    public List<String> generateParenthesis(int n) {
        Stack<Character> s = new Stack<Character>();
        List<String> r = new ArrayList<String>();
        backTracking(0, 0, n, s, r);
        return r;
    }
}