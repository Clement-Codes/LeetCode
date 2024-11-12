class Solution {
public:
    bool isPrime(int n){
        for (int i = 2; i < int(sqrt(n)) + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    int getMax(vector<int>& nums){
        int res = INT_MIN;
        for(int i: nums)
            if (res < i)
                res = i;
        return res;
    }
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;

        // vector<bool> primes = {false, false};
        vector<int> primes = {0, 0};
        int maxi = getMax(nums);
        for (int i = 2; i < maxi; i++)
            if (isPrime(i)){
                primes.push_back(i);
            }
            else{
                primes.push_back(primes[primes.size() - 1]);
            }

        for (int n: nums){
            int upperbound = n - prev;
            int largest_prime = upperbound - 1 >=0 ? primes[upperbound - 1] : primes[primes.size()  + (upperbound - 1)];
            // for (int i = upperbound - 1; i >=2; i--){
            //     if (primes[i]){
            //         largest_prime = i;
            //         break;
            //     }
            // }
            if (n  - largest_prime <= prev)
                return false;
            prev = n - largest_prime;
        }
        return true;
    }
};