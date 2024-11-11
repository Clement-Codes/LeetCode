class Solution {
public:
    bool isPrime(int n){
        for (int i = 2; i < int(sqrt(n)) + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    } 

    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for (int n: nums){
            int upperbound = n - prev;
            int largest_prime = 0;
            for (int i = upperbound - 1; i >=2; i--){
                if (isPrime(i)){
                    largest_prime = i;
                    break;
                }
            }
            if (n  - largest_prime <= prev)
                return false;
            prev = n - largest_prime;
        }
        return true;
    }
};