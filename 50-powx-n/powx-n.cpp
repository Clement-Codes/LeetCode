class Solution {
public:
    double helper(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        double temp = myPow(x, n/2);
        temp = temp* temp;
        return n % 2 == 1?  x * temp : temp; 
    }
    double myPow(double x, int n) {
        double result = helper(x, abs(n));
        return n > 0 ? result : 1/result;
    }
};