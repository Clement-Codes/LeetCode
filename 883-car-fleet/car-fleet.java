import java.util.Collection;
import java.util.Stack;

class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        Stack<Double> s = new Stack<Double>();
        int cars [][] = new int[position.length][2];

        for(int i = 0; i < position.length; i++){
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        Arrays.sort(cars, (a,b) -> Integer.compare(b[0], a[0]));

        for(int car[]: cars){
            double p = (target - car[0])/(double)car[1];
            if (s.size() == 0 || p>s.peek()){
                s.push(p);
            }
        }
        return s.size();
    }
}