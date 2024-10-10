class Solution {
public:
    int sumOfSquares(int n){
        int output = 0;
        while (n > 0){
            output += pow(n % 10, 2);
            n = n/10;
        }
        return output;
    }
    bool isHappy(int n) {
        unordered_set<int> cache;
        while (!cache.contains(n)){
            cache.insert(n);
            n = sumOfSquares(n);
            if (n == 1) return true;
        }
        return false;
    }
};