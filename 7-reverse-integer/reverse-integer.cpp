class Solution {
public:
    int reverse(int x) {
        int MIN = -2147483648;
        int MAX = 2147483647;
        int result = 0;

        while (x != 0){
            int digit = x % 10;
            x = x / 10;
            if (result > MAX / 10 || (result == MAX / 10 && digit > MAX % 10)) return 0;
            if (result < MIN / 10 || (result == MIN / 10 && digit < MIN % 10)) return 0;
            result = (result * 10) + digit;
        }
        return result;
    }
};