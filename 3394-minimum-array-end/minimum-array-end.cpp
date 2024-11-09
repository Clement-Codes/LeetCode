class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x, i_x = 1, i_n = 1;
        while (i_n <= n - 1){
            cout << res << " " << i_x << " " << i_n << " " << "\n"; 
            if ((i_x & x) == 0){
                if ((i_n & (n - 1)) > 0){
                    res = (res | i_x);
                }
                i_n = i_n << 1;
            }
            i_x = i_x << 1;   
        }
        return res;

        // for loop
        // long long res = x;
        // for (int i = 0; i < n - 1; i++)
        //     res = (res + 1) | x;
        // return res;
    }
};