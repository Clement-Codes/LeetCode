class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        while(n-1){
            int temp = one;
            one += two;
            two = temp;
            n -= 1;
        }
        return one;
    }
};