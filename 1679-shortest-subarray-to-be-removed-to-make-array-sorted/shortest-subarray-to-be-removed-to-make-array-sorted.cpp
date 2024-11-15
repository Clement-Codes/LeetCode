class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n - 1;
        while (r > 0 && arr[r - 1] <= arr[r])
            r -= 1;
        int res = r;

        int l = 0;
        while (l < n - 1 && arr[l] <= arr[l + 1])
            l+= 1;
        res = min(res, n - l - 1);

        l = 0;
        r = n - 1;
        while (l < r){
            while (r < n && l + 1 < r && arr[r - 1] <= arr[r] && arr[l] <= arr[r])
                r -= 1;
            
            while (r < n && arr[l] > arr[r])
                r += 1;
            
            res = min(res, r - l - 1);
            if (arr[l] > arr[l + 1]) break;

            l += 1;
        }
        return res;
    }
};