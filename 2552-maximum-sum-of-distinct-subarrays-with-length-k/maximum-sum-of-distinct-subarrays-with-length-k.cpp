class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //loops with skip
        long long result = 0;
        int l = 0;
        int n = nums.size();
        long long sum = 0;
        unordered_map<int, int> prevPos;
        for (int r = 0; r < n; r++){
            sum += nums[r];

            while (l <= (prevPos.contains(nums[r]) ? prevPos[nums[r]] : -1) || r - l + 1 > k){
                sum -= nums[l];
                l += 1;
            }


            if (r - l + 1 == k){
                result = max(result, sum);
            }

            prevPos[nums[r]] = r;
        }
        return result;        
        // loops
        // long long result = 0;
        // int l = 0;
        // int n = nums.size();
        // long long sum = 0;
        // unordered_map<int, int> counter;
        // for (int r = 0; r < n; r++){
        //     sum += nums[r];
        //     if (counter.find(nums[r]) != counter.end())
        //         counter[nums[r]] += 1;
        //     else
        //         counter[nums[r]] = 1;

        //     if (r - l + 1 > k){
        //         counter[nums[l]] -= 1;
        //         if (counter[nums[l]] == 0)
        //             counter.erase(nums[l]);
        //         sum -= nums[l];
        //         l += 1;
        //     }


        //     if (r - l + 1 == k && counter.size() == k){
        //         result = max(result, sum);
        //     }
        // }
        // return result;
    }
};