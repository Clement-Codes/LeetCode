class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int result = 0;
        while (l <= r){
            int m = l + int((r - l) / 2);
            int s = 0;
            for(float q: quantities)
                s += ceil(q/m);
            if (s <= n){
                r = m - 1;
                result = m;
            }
            else l = m + 1;
        }
        return result;
    }
};