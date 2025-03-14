class Solution {
    public boolean isPrime(int n){
        for (int i = 2; i < (int)(Math.sqrt(n)) + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    } 

    public int getMax(int[] nums){
        int res = Integer.MIN_VALUE;
        for(int i: nums)
            if (res < i)
                res = i;
        return res;
    }
    
    public boolean primeSubOperation(int[] nums) {
        int prev = 0;

        List<Integer> primes = new ArrayList<Integer>();
        int maxi = getMax(nums);
        primes.add(0);
        primes.add(0);
        for (int i = 2; i < maxi; i++)
            if (isPrime(i)){
                primes.add(i);
            }
            else{
                primes.add(primes.get(primes.size() - 1));
            }

        for (int n: nums){
            int upperbound = n - prev;
            int largest_prime = upperbound - 1 >=0 ? primes.get(upperbound - 1) : primes.get(primes.size()  + (upperbound - 1));

            //int largest_prime = 0;
            // for (int i = upperbound - 1; i >=2; i--){
            //     // if (isPrime(i)){
            //     if (primes.get(i)){

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
}